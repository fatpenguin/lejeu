#!/bin/bash

clear

echo "[*] Run project setup"
if command -v brew >/dev/null; then {
        echo "[-] Brew is already installed"
    }
    else { 
        echo >&2 "[-] Brew is not installed. Installing brew.";
        /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"; 
        exit 1; 
    }
fi

if brew ls --versions sfml >/dev/null; then {
        echo "[-] Sfml is already installed"
    }
    else { 
        echo >&2 "[-] Brew is not installed. Installing brew.";
        /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"; 
        exit 1; 
    }
fi

echo "[*] Setup done"