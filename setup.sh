#!/usr/bin/env bash

BASEDIR=$(dirname "$0")

# Source command
SOURCE="source"

# Check which shell environrment is executing the script and 
# depending on the shell environment change source command
if test -n "$ZSH_VERSION"; then
  PROFILE_SHELL=zsh
  SOURCE="$SOURCE"
elif test -n "$BASH_VERSION"; then
  PROFILE_SHELL=bash
  SOURCE="$SOURCE"
elif test -n "$KSH_VERSION"; then
  PROFILE_SHELL=ksh
  SOURCE="$SOURCE"
elif test -n "$FCEDIT"; then
  PROFILE_SHELL=ksh
  SOURCE="$SOURCE"
elif test -n "$PS3"; then
  PROFILE_SHELL=unknown
  SOURCE="$SOURCE"
else
  PROFILE_SHELL=sh
  SOURCE="$BASEDIR"
fi

echo "[Running]: Script under \`$PROFILE_SHELL\` environment"

# Execute the config configuration
"$SOURCE" "$BASEDIR/scripts/linux/config.sh"

# Execute the build script
"$SOURCE" "$BASEDIR/scripts/linux/build.sh"
