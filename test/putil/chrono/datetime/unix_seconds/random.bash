set -ex

unix="$(echo "$0" | sed 's@/@\n@g' | tail -n2 | head -n1)"

string="$(date -d @$unix)"

parsed="$($PTEST_BINARY "$string")"

if [[ "$unix" != "$parsed" ]]
then
    exit 1
fi

exit 0
