#!/bin/bash -e

# Upload cairomm documentation to cairographics.org/documentation/cairomm/reference
# Run this script from the root of the build tree, typically cairomm/.

if [ $# -ne 2 ]
then
  echo "Usage: $0 <version> <username>"
  echo "Example: $0 1.14.0 foo"
  exit 1
fi

PACKAGE=cairomm
VERSION=$1
USERNAME=$2

RELEASE_UPLOAD_HOST=cairographics.org
RELEASE_UPLOAD_BASE=/srv/cairo.freedesktop.org/www

DOC_UNVERSIONED=$PACKAGE-doc
DOC_VERSIONED=$PACKAGE-doc-$VERSION
DOC_TAR_FILE_UNVERSIONED=$DOC_UNVERSIONED.tar.gz
DOC_TAR_FILE_VERSIONED=$DOC_VERSIONED.tar.gz
DOC_UPLOAD_DIR=$RELEASE_UPLOAD_BASE/documentation/$PACKAGE/reference

# Make two tarballs with only the reference documentation.
#
# DOC_TAR_FILE_UNVERSIONED contains the files in directory DOC_VERSIONED/html.
# There's a link from https://www.cairographics.org/cairomm
# to DOC_UPLOAD_DIR/DOC_TAR_FILE_UNVERSIONED.
#
# DOC_TAR_FILE_VERSIONED contains the same files, but no directory name.
# It's better suited for extraction in DOC_UPLOAD_DIR.
rm -rf $DOC_VERSIONED
mkdir $DOC_VERSIONED
cp -a docs/reference/html $DOC_VERSIONED
tar czf $DOC_TAR_FILE_UNVERSIONED $DOC_VERSIONED
cd $DOC_VERSIONED/html
tar czf ../../$DOC_TAR_FILE_VERSIONED .
cd ../..

# Upload both tarballs and extract DOC_TAR_FILE_VERSIONED.
# The extracted files are stored in DOC_UPLOAD_DIR.
scp $DOC_TAR_FILE_UNVERSIONED $DOC_TAR_FILE_VERSIONED $USERNAME@$RELEASE_UPLOAD_HOST:$DOC_UPLOAD_DIR
ssh $USERNAME@$RELEASE_UPLOAD_HOST "cd $DOC_UPLOAD_DIR && tar xzf $DOC_TAR_FILE_VERSIONED"
