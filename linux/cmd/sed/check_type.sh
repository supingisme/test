#!/bin/bash
 
function check(){
    local a="$1"
    printf "%d" "$a" &>/dev/null && echo "integer" && return
    printf "%d" "$(echo $a|sed 's/^[+-]\?0\+//')" &>/dev/null && echo "integer" && return
    printf "%f" "$a" &>/dev/null && echo "number" && return
    [ ${#a} -eq 1 ] && echo "char" && return
    echo "string"
}
 
echo ". is" $(check ".")
echo "1 is" $(check "1")
echo ".1 is" $(check ".1")
echo "1. is" $(check "1.")
echo "1234 is" $(check "1234")
echo "1.234 is" $(check "1.234")
echo "1.2.3.4 is" $(check "1.2.3.4")
echo "a1234 is" $(check "a1234")
echo "abc is" $(check "abc")
echo "a is" $(check "a")
echo "1e+2" $(check "1e+2")
echo "1.e+2" $(check "1e+2")
echo ".1e+2" $(check "1e+2")
echo "-1" $(check "-1")
echo "-1.2" $(check "-1.2")
echo "-a" $(check "-a")
echo "0x1f" $(check "0x1f")
echo "0x1H" $(check "0x1H")
echo "0333" $(check "0333")
echo "0999" $(check "0999")
echo "+003" $(check "+003")
echo "+003.3" $(check "+003.3")
