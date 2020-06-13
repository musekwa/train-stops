

struct Estacao {
  char sigla;
  struct Estacao* proxima;
  struct Estacao* anterior;
};

//Estacao de partida
struct Estacao* inicial; 
