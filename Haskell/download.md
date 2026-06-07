sudo pacman -Syu base-devel libffi gmp ncurses perl make ghc

curl --proto '=https' --tlsv1.2 -sSf https://get-ghcup.haskell.org | sh

load: 
    ghci , :load projekt_name 