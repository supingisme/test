#!/bin/bash 

# Convert main.c.0.lpmakeorig -> main.c
restore_origs() {
    find $srcdir -regex '.+\.[0-9]+\.lpmakeorig' | awk '
    {
        origfname = $0;
        gsub(".[0-9]+.lpmakeorig$", "");
        fname = $0;
        if (!vers[fname] || vers[fname] > origfname)
            { vers[fname] = origfname; }
    }
    END { for (f in vers) system("mv " vers[f] " " f); }
'
}
                                                                                                                             
# src + patch = patch.src
# and trap singal like SIGINT
trap "restore_origs" 0


while :;
do
	sleep 1
done
