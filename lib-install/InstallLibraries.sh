#!/bin/bash

# Directory of this script
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

cp --verbose -r $DIR/lib/* ~/wpilib/user/cpp/lib
cp --verbose -r $DIR/include/* ~/wpilib/user/cpp/include

echo ""
echo "RESTART ECLIPSE!!!"
echo "Press any key to continue..."

# Wait for keypress
read -n 1 -s
