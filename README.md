# Projet tutoré C
**Subject 9 : Splashmem with SDL3**

# Présentation équipe
* **Florian GRELIER**
    * CDC
    * DEV
    * PPT
* **David PIGEONNEAU**
    * CDC
    * DEV
    * PPT
* **David PIGEONNEAU**
    * CDC
    * DEV
    * PPT
* **Jonas BOURREAU**
    * CDC
    * DEV
    * CEO
    * PPT
# Présentation sujet
**Assurer la transition de Splashmem de la bibliothèque SDL2 à la nouvelle (SDL3) sorti récemment.**  

# **Présentation détaillé**
## 1. Règles du jeu

Creation of a multiplayer game, with a maximum of 4 players. Each player is a program whose goal is to fill memory squares. The program/player that fills the most squares with its credits wins the game.

Each player have 9000 credits.

| Code | Cost | Action|
|------|:----:|:------|
|ACTION_MOVE_L| 1 | Move player of the block |
|ACTION_MOVE_R| 1 | Move player of the block |
|ACTION_MOVE_U| 1 | Move player of the block |
|ACTION_MOVE_D| 1 | Move player of the block |
|ACTION_DASH_L | 10 | Move player of 8 block in one direction |
|ACTION_DASH_R | 10 | Move player of 8 block in one direction |
|ACTION_DASH_U | 10 | Move player of 8 block in one direction |
|ACTION_DASH_D | 10 | Move player of 8 block in one direction |
|ACTION_TELEPORT_L | 4 | Teleport player 8 blocks away |
|ACTION_TELEPORT_R | 4 | Teleport player 8 blocks away|
|ACTION_TELEPORT_U | 4 | Teleport player 8 blocks away|
|ACTION_TELEPORT_D | 4 | Teleport player 8 blocks away|
|ACTION_SPLASH |8 | Marque toute les cases autour du joueur |
|ACTION_BOMB |9 | Place une bombe qui marque 9 cases et qui ce déclenche après 5 tours |
|ACTION_STILL |1 | Pas d'action |


As soon as a player lands on a square, it is automatically marked.

The game board size is 100 squares by 100 squares.
Each player starts at the same distance.
When a player exceeds an edge, they are sent back to the opposite side (Pacman effect).

Each player-program has ```x,y``` coordinates, with the coordinate ```(0,0)``` at the top-left corner of the playing area.

## 2. Technologies utilisées
* SDL3
* C
* GitHub
* VSCode
* Teams

## 3. Découpage technique du sujet 
1. Connaitre les différences et les présenter
2. Effectuer des changements qui fonctionne
