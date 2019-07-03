#!/bin/bash

readonly jogo="main"; # O script a ser executado

chmod +x $jogo;
gnome-terminal -x bash -c "./$jogo; exec $SHELL";

#Continua a execução do script

echo "iniciando";
echo ".........";
