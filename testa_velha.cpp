
/**
 * \file testa_velha.cpp
 * Copyright 2021 Gabriel Cruz
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Ganhar pela coluna", "[single-file]") {
    int teste1[3][3]= { { 2, 0, 1 },
                        { 2, 0, 1 },
                        { 0, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste1) == 1);

    int teste2[3][3]= { { 2, 1, 1 },
                        { 2, 0, 1 },
                        { 2, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste2) == 2);

    int teste3[3][3]= { { 2, 0, 1 },
                        { 2, 0, 1 },
                        { 0, 0, 1 }
                      };
    REQUIRE(VerificaVelha(teste3) == 1);

    int teste4[3][3]= { { 2, 0, 1 },
                        { 2, 0, 0 },
                        { 2, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste4) == 2);

    int teste5[3][3]= { { 2, 1, 0 },
                        { 0, 1, 0 },
                        { 2, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste5) == 1);


    int teste6[3][3]= { { 1, 2, 0 },
                        { 1, 0, 0 },
                        { 1, 2, 2 }
                      };
    REQUIRE(VerificaVelha(teste6) == 1);

    int teste7[3][3]= { { 1, 2, 0 },
                        { 0, 2, 1 },
                        { 1, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste7) == 2);

    int teste8[3][3]= { { 1, 0, 2 },
                        { 0, 1, 2 },
                        { 1, 0, 2 }
                      };
    REQUIRE(VerificaVelha(teste8) == 2);
}

TEST_CASE("Ganhar pela linha", "[single-file]") {
    int teste1[3][3]= { { 2, 2, 2 },
                        { 2, 1, 1 },
                        { 0, 0, 1 }
                      };
    REQUIRE(VerificaVelha(teste1) == 2);

    int teste2[3][3]= { { 2, 2, 0 },
                        { 1, 1, 1 },
                        { 0, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste2) == 1);

    int teste3[3][3]= { { 0, 0, 0 },
                        { 2, 0, 2 },
                        { 1, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste3) == 1);

    int teste4[3][3]= { { 1, 1, 1 },
                        { 2, 0, 2 },
                        { 0, 0, 0 }
                      };
    REQUIRE(VerificaVelha(teste4) == 1);

    int teste5[3][3]= { { 2, 1, 1 },
                        { 2, 2, 2 },
                        { 0, 0, 1 }
                      };
    REQUIRE(VerificaVelha(teste5) == 2);

    int teste6[3][3]= { { 2, 1, 1 },
                        { 0, 0, 1 },
                        { 2, 2, 2 }
                      };
    REQUIRE(VerificaVelha(teste6) == 2);
}

TEST_CASE("Ganhar pela diagonal", "[single-file]") {
    int teste1[3][3]= { { 2, 1, 1 },
                        { 0, 2, 0 },
                        { 1, 0, 2 }
                      };
    REQUIRE(VerificaVelha(teste1) == 2);

    int teste2[3][3]= { { 2, 2, 1 },
                        { 0, 1, 0 },
                        { 1, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste2) == 1);

    int teste3[3][3]= { { 1, 2, 1 },
                        { 2, 1, 2 },
                        { 1, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste3) == 1);

    int teste4[3][3]= { { 1, 1, 2 },
                        { 0, 2, 0 },
                        { 2, 0, 1 }
                      };
    REQUIRE(VerificaVelha(teste4) == 2);


    int teste5[3][3]= { { 0, 1, 2 },
                        { 1, 0, 0 },
                        { 2, 0, 0 }
                      };
    REQUIRE(VerificaVelha(teste5) == -1);
}

TEST_CASE("indefinido", "[single-file]") {
    int teste1[3][3]= { { 0, 1, 1 },
                        { 0, 2, 0 },
                        { 1, 0, 2 }
                      };
    REQUIRE(VerificaVelha(teste1) == -1);

    int teste2[3][3]= { { 0, 0, 0 },
                        { 0, 0, 0 },
                        { 1, 0, 0 }
                      };
    REQUIRE(VerificaVelha(teste2) == -1);

    int teste3[3][3]= { { 0, 0, 0 },
                        { 0, 0, 0 },
                        { 0, 0, 0 }
                      };
    REQUIRE(VerificaVelha(teste3) == -1);

    int teste4[3][3]= { { 1, 2, 1 },
                        { 2, 2, 1 },
                        { 1, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste4) == 0);
}

TEST_CASE("empate", "[single-file]") {
    int teste1[3][3]= { { 1, 2, 1 },
                        { 2, 2, 1 },
                        { 1, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste1) == 0);

    int teste2[3][3]= { { 1, 2, 2 },
                        { 2, 1, 1 },
                        { 2, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste2) == 0);
}

TEST_CASE("imposs??vel pelas regras", "[single-file]") {
    int teste1[3][3]= { { 1, 1, 1 },
                        { 1, 1, 1 },
                        { 1, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste1) == -2);

    int teste2[3][3]= { { 1, 1, 1 },
                        { 1, 2, 2 },
                        { 1, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste2) == -2);

    int teste3[3][3]= { { 1, 0, 2 },
                        { 1, 0, 2 },
                        { 1, 0, 2 }
                      };
    REQUIRE(VerificaVelha(teste3) == -2);

    int teste4[3][3]= { { 2, 2, 2 },
                        { 0, 0, 0 },
                        { 1, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste4) == -2);

    int teste5[3][3]= { { 8, 2, 2 },
                        { 0, 0, 0 },
                        { 1, 1, -2 }
                      };
    REQUIRE(VerificaVelha(teste5) == -2);
}



