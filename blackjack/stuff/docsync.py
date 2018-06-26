#!/usr/bin/env python

import pdb
import sys

# 1. Tokenize all files

def tokenize_file(fpath):
    src_fd = open(fpath)
    src = src_fd.read()
    src_fd.close()

    out = []
    start = 0;
    start_delim = '/**'
    end_delim = '*/'
    while start < len(src): 
        cmt_begin = src.find(start_delim, start)
        if cmt_begin == -1:
            # We're done with this file
            if start > 0:
                #print "After all comments: " + src[start + len(end_delim):]
                out.append(src[start + len(end_delim):])
            else:
                #print "After all comments: " + src[start:]
                out.append(src[start:])
            break
        if start > 0:
            #print "Before comment:" + src[start + len(end_delim):cmt_begin]
            out.append(src[start + len(end_delim):cmt_begin])
        else:
            #print "Before comment:" + src[start:cmt_begin]
            out.append(src[start:cmt_begin])
        cmt_end = src.find(end_delim, cmt_begin)
        if cmt_end == -1:
            # We're done with this file
            #print "WARNING: Comment started without close."
            break
        #print "Current Comment: " + src[cmt_begin:cmt_end + len(end_delim)]
        out.append(src[cmt_begin:cmt_end + len(end_delim)])
        start = cmt_end
    return out

def process_files():

    exports = {}

    for fpath in sys.argv[1:]:
        print "Processing exports for " + fpath
        out = tokenize_file(fpath)

        # 2. Grab all the exports on the first pass
        export_delim = '[docexport]'
        for token in out:
            export_idx = token.find(export_delim)
            if export_idx != -1:
                export_name = token[export_idx:].split()[1]
                if exports.has_key(export_name):
                    print "ERROR: Duplicate export found (%s)." % (export_name)
                exports[export_name] = token.replace('docexport', 'docimport')

    for fpath in sys.argv[1:]:
        print "Processing imports for " + fpath
        out = tokenize_file(fpath)

        # 3. Replace any imports with found export
        import_delim = '[docimport]'
        new_src = []
        for token in out:
            import_idx = token.find(import_delim)
            if import_idx != -1:
                import_name = token[import_idx:].split()[1]
                if not exports.has_key(import_name):
                    print "WARNING: Requested import not found (%s)." % (import_name)
                    continue
                if exports[import_name] != token:
                    new_src.append(exports[import_name])
                    continue
            new_src.append(token)
        src_fd = open(fpath, "wb")
        src_fd.write(''.join(new_src))
        src_fd.close()

process_files()

#pdb.set_trace()

