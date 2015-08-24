set -ex

date="$(date +%s)"
putil="$($PTEST_BINARY)"

if [[ "$((($putil - $date)))" > 1 ]]
then
    exit 1
fi

exit 0

