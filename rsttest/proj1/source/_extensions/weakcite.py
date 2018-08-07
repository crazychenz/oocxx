from docutils import nodes
from sphinx.addnodes import pending_xref
from docutils.parsers.rst import Directive, directives

# 1. Define a table of global citations in conf.py
#   global_citations = {
#      'thing1': {
#          'author': 'auth1',
#          'title': 'Project 1 Documentation',
#          'date': 'the date',
#          'ref': 'proj2:proj2_index',
#      },
#      'thing2': {
#          'author': 'auth2',
#          'title': 'Project 2 Documentation',
#          'date': 'the date',
#          'ref': 'proj2:proj2_index',
#      },
#      'thing3': {
#          'author': 'auth3',
#          'title': 'Project 3 Documentation',
#          'date': 'the date',
#          'ref': 'proj2:proj2_index',
#      },
#  }
#
# 2. Define a 'database' of references in the prologue by
#    exploiting the fact that string replace will eval :ref:
#
#   def ftnote_ref_entry(key):
#       return '.. |%s| replace:: :ref:`%s <%s>`' % \
#           (key, global_citations[key]['title'], global_citations[key]['ref'])
# 
#   def ftnote_ref_entries(bib):
#       lst = []
#       for key in bib:
#           lst.append(ftnote_ref_entry(key))
#       return lst
#
#   # Create (resolved) reference entries for all refs (as substitution entries) in the prolog
#   ftnote_map_prolog = ftnote_ref_entries(global_citations)
# 
#   rst_prolog = '\n'.join(ftnote_map_prolog)
#
# 3. Add references to global citations in RST files with :gcite:
#
#   :gcite:`thing1`
#
# 4. Add the ftnotes directive to the end of the page.
#
#   .. ftnotes::
#
#

# Out database for footnotes this go round.
ftnote_lst = []

# ftnote_pxref() extracts/copies the pending_xref from the prolog as a node.
def ftnote_pxref(doc, ref):
    #<pending_xref 
    #  refdoc="index" 
    #  refdomain="std" 
    #  refexplicit="True" 
    #  reftarget="proj2:proj2_index" 
    #  reftype="ref" 
    #  refwarn="True">
    #    <inline classes="xref std std-ref">Project 2 Documentation</inline>
    #  </pending_xref>
    pxref = doc.substitution_defs[ref].children[0]
    inln = doc.substitution_defs[ref].children[0][0]
    ftnote_pxref = pending_xref(
        #text=pxref.astext(),
        refdoc=pxref['refdoc'],
        refdomain=pxref['refdomain'],
        refexplicit=pxref['refexplicit'],
        reftarget=pxref['reftarget'],
        reftype=pxref['reftype'],
        refwarn=pxref['refwarn'])
    ftnote_pxref.append(nodes.inline(text=inln.astext(), classes=inln['classes']))
    return ftnote_pxref

# Replaces the provided global_citations key with a reference/title 
# and psuedo subscript that is a footnote reference.
#
# :gcite:`key-goes-here`
#

def gcite_role(name, rawtext, text, lineno, inliner, options={}, content=[]):
    """ weakcite role definition

        :param name: The role name used in the document.
        :param rawtext: The entire markup snippet, with role.
        :param text: The text marked with the role.
        :param lineno: The line number where rawtext appears in the input.
        :param inliner: The inliner instance that called us.
        :param options: Directive options for customization.
        :param content: The directive content for customization.
    """
    global ftnote_lst
    #<footnote_reference auto="1" ids="id1" refid="proj2">1</footnote_reference>
    
    ftnote_lst.append(text)
    ftnote_idx = len(ftnote_lst)
    ftnote_ref = nodes.footnote_reference( \
        text=str(ftnote_idx), 
        auto="1", 
        ids="id%d" % ftnote_idx, 
        refid=text)

    return [ftnote_pxref(inliner.document, text), ftnote_ref],[]

# This directive dumps all the referenced global citations as footnotes.
class FtNotes(Directive):
    has_content = True

    def run(self):
        global ftnote_lst

        #<footnote auto="1" backrefs="id1" ids="proj2" names="proj2">
        #   <label>1</label>
        #   <paragraph>Project 2 Documentation, v3 2018</paragraph>
        #</footnote>

        ftnotes = []
        ftnote_idx = 0
        for ref in ftnote_lst:
            entry = self.state.document.settings.env.app.config.global_citations[ref]
            ftnote_idx += 1 
            ftnote = nodes.footnote(auto="1", backrefs="id%d" % ftnote_idx, ids=ref, names=ref)
            ftnote += nodes.label(text="%d" % ftnote_idx)
            ftnote_para = nodes.paragraph()
            ftnote_para += nodes.Text(" %s. " % entry['author'])
            ftnote_para += ftnote_pxref(self.state.document, ref)
            ftnote_para += nodes.Text(".")
            ftnote_para += nodes.Text(" %s. " % entry['date'])
            ftnote += ftnote_para
            ftnotes.append(ftnote)

        # Wipe this list. (This makes this directive non-reentrant.)
        # TODO: Find a way to execute this on "exit <document>" event.
        while (len(ftnote_lst) > 0):
            ftnote_lst.pop()

        return ftnotes

def setup(app):
    # Register the :gcite: (global cite) role.
    app.add_role('gcite', gcite_role)

    # Register the ftnotes (footnotes) directive.
    app.add_directive('ftnotes', FtNotes)

    # Create a configuration value to store global citations.
    # Note: Rebuild everything if this value changes.
    app.add_config_value('global_citations', None, 'env')

