#!/bin/sh
#
# Show the given interface's ethernet MAC.

set -e

export LANG=C

if [ ! "$1" ] ; then
	echo "Usage: $0 IFACE"
	exit 1
fi
iface="$1"
mac=$(/sbin/ifconfig "$iface" | sed -n -e '/^.*HWaddr \([:[:xdigit:]]*\).*/{s//\1/;y/abcdef/ABCDEF/;p;q;}')

echo $mac
