set -ex

tempdir=`mktemp -d -t ptest.XXXXXXXXXX`
trap "rm -rf $tempdir" EXIT
cd $tempdir

$PTEST_BINARY $DIRECTORY_TO_MAKE


[[ "$(find -type f | wc -l)" == 0 ]] || exit 2

[[ "$(find -type d -depth -empty | wc -l)" == 1 ]] || exit 2
