#/bin/bash

BANNER="$(
  cat <<-EOF
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    link_all_cache_dirs.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 15:50:44 by jaeskim           #+#    #+#              #
#    Updated: 2021/05/18 16:28:39 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
EOF
)"

TARGET=(
  "Caches"
  "ApplicationSupport/Code/Cache"
  "ApplicationSupport/Code/CachedData"
  "ApplicationSupport/Code/CachedExtensions"
  "ApplicationSupport/Code/CachedExtensionVSIXs"
  "ApplicationSupport/Code/Code Cache"
  "ApplicationSupport/Slack/Cache"
  "ApplicationSupport/Slack/CachedData"
  "ApplicationSupport/Slack/Service Worker/CacheStorage"
  "ApplicationSupport/Slack/Service Worker/ScriptCache"
)

FLAG="$HOME/goinfre/issetup"

function link_all_cache_dirs() {
  echo "link Code Slack Cache dirs..."
  for ((i = 0; i < ${#TARGET[@]}; i++)); do
    mkdir -p "$HOME/goinfre/${TARGET[$i]}"
    rm -rf "$HOME/Library/${TARGET[$i]}"
    ln -s "$HOME/goinfre/${TARGET[$i]}" "$HOME/Library/${TARGET[$i]}"
  done
  echo "Complete link all Cache dirs!"
  touch "$FLAG"
}

ASK=false
if [ -e "$FLAG" ]; then
   	ASK=true 
fi

if $ASK ; then
	printf "Would you like to run it again? [y/n] "
	read -n1
	if [[ "$REPLY" == "y" ]]; then
		rm ./goinfre/issetup; 
	fi
fi

echo

if [ ! -e "$FLAG" ]; then
  printf "\n$BANNER\n"
  link_all_cache_dirs
fi
