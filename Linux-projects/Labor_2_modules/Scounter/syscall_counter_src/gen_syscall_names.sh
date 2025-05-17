#!/bin/bash

# author: Rainer Keller
# description: generate a syscall name array from the linux source tree
# by considering the syscall_64.tbl file which is different for certain CPU architectures (x86_64, aarch64, etc.)
#
# usage: ./gen_syscall_names.sh <path_to_linux_source_tree> or via the  provided Makefile

SRC=$1

if ! test -d $SRC ; then
    echo "ERROR: First argument:$1 should contain directory to linux' source tree"
    exit 1
fi

ARCH="$(uname -m)"
case "$ARCH" in
    "x86_64")
        FILE_IN=$SRC/arch/x86/entry/syscalls/syscall_64.tbl
        ;;
    "aarch64")
        FILE_IN=$SRC/arch/arm64/tools/syscall_64.tbl
        ;;
    *)
        echo "Architecture $ARCH not yet supported"
        ;;
esac

if ! test -f $FILE_IN ; then
    echo "ERROR: File $FILE_IN not found. Architecture supported?"
    exit 1
fi
FILE_OUT=syscall_names.h

echo "/* AUTO-GENERATED. DO NOT EDIT. */" > $FILE_OUT
echo "/* Syscall array, mapping $ARCH's syscall-ID to this syscall's name */" >> $FILE_OUT
echo "#ifndef __SYSCALL_ARR_H__" >> $FILE_OUT
echo "#define __SYSCALL_ARR_H__" >> $FILE_OUT
echo "" >> $FILE_OUT
echo "static const char * const syscall_names[] = {" >> $FILE_OUT

grep -E "^[0-9]+[[:space:]]+" "$FILE_IN" | {
    i=1
    LAST_ID=0
    while read ID ABI NAME NATIVE COMPAT NORETURN ; do
        # Some IDs have two implementation names (are duplicated): skip
        if test $LAST_ID -eq $ID ; then
            continue
        fi
    
        while test $i -lt $ID ; do
            echo "    \"N/A\", // i:$i ID:$ID"
            i=$(( $i + 1 ))
        done
        echo "    \"$NAME\", // i:$i ID:$ID"
        LAST_ID=$ID
        i=$(( $i + 1 ))
    done 
} >> $FILE_OUT

echo "};" >> $FILE_OUT
echo "" >> $FILE_OUT
echo "#endif /* __SYSCALL_ARR_H__ */" >> $FILE_OUT
