set -ex

tempdir=`mktemp -d -t ptest.XXXXXXXXXX`
trap "rm -rf $tempdir" EXIT
cd $tempdir

out="$($PTEST_BINARY $ARGS)"
if [[ "$out" != "$GOLD" ]]
then
    exit 1
fi
