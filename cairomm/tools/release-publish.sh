#!/bin/bash -e

# Upload a cairomm tarball to cairographics.org/releases

# Before you call this script, make a tarball with 'meson dist' or 'make distcheck'
# as described at https://wiki.gnome.org/MaintainersCorner/Releasing
# but DO NOT upload it to master.gnome.org.
# Run this script from the build tree directory where the tarball is.

if [ $# -ne 2 ]
then
  echo "Usage: $0 <version> <username>"
  echo "Example: $0 1.14.0 foo"
  exit 1
fi

PACKAGE=cairomm
VERSION=$1
USERNAME=$2
tar_file=$PACKAGE-$VERSION.tar.xz
sha1_file=$tar_file.sha1
gpg_file=$sha1_file.asc

RELEASE_UPLOAD_HOST=cairographics.org
RELEASE_UPLOAD_BASE=/srv/cairo.freedesktop.org/www
RELEASE_UPLOAD_DIR=$RELEASE_UPLOAD_BASE/releases

# Create a checksum file, and sign it.
sha1sum $tar_file >$sha1_file
echo "Please enter your GPG password to sign the checksum."
gpg --armor --sign $sha1_file

# Upload the tarball, checksum file and signature file.
scp $tar_file $sha1_file $gpg_file $USERNAME@$RELEASE_UPLOAD_HOST:$RELEASE_UPLOAD_DIR

# Update the LATEST-$PACKAGE link.
ssh $USERNAME@$RELEASE_UPLOAD_HOST "rm -f $RELEASE_UPLOAD_DIR/LATEST-$PACKAGE-[0-9]* && ln -s $tar_file $RELEASE_UPLOAD_DIR/LATEST-$PACKAGE-$VERSION"

# Sign the tarball, and upload the detached signature file.
# This is a preliminary fix. If cairo releases will be signed differently
# in the future, cairomm should be changed accordingly.
# https://gitlab.freedesktop.org/cairo/cairomm/-/issues/25
# https://gitlab.freedesktop.org/cairo/cairo/-/issues/458
#gpg --armor --detach-sign $tar_file
#scp $tar_file.asc $USERNAME@$RELEASE_UPLOAD_HOST:$RELEASE_UPLOAD_DIR

# Move the files to a subdir.
#mkdir -p releases
#mv $tar_file $sha1_file $gpg_file releases
