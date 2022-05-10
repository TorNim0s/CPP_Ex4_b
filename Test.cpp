#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace std;
using namespace coup;
// using namespace coup;

TEST_CASE("Game Flow")
{
    Game game{};

    Contessa contessa{game, "Shir"};
	Duke duke{game, "Ilan"};
	Assassin assassin{game, "Eldad"};
    Captain captain{game, "David"};
	Ambassador ambassador{game, "Roni"};

    // round 1 everyone takes a coin

	CHECK(game.turn() == "Shir");
	CHECK(contessa.coins() == 0);
    CHECK_NOTHROW(contessa.income());
    CHECK(contessa.coins() == 0);
	CHECK(game.turn() == "Ilan");
	CHECK(duke.coins() == 0);
	CHECK_NOTHROW(duke.income());
	CHECK(duke.coins() == 1);
	CHECK(game.turn() == "Eldad");
	CHECK(assassin.coins() == 0);
	CHECK_NOTHROW(assassin.income());
	CHECK(assassin.coins() == 1);
	CHECK(game.turn() == "David");
	CHECK(captain.coins() == 0);
	CHECK_NOTHROW(captain.income());
	CHECK(captain.coins() == 1);
	CHECK(game.turn() == "Roni");
	CHECK(ambassador.coins() == 0);
	CHECK_NOTHROW(ambassador.income());
	CHECK(ambassador.coins() == 1);

    // end of round 1

    // round 2 take 2 coins each

	CHECK(game.turn() == "Shir");
	CHECK(contessa.coins() == 1);
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK(contessa.coins() == 3);
    CHECK(game.turn() == "Ilan");
	CHECK(duke.coins() == 1);
	CHECK_NOTHROW(duke.foreign_aid());
	CHECK(duke.coins() == 3);
	CHECK(game.turn() == "Eldad");
	CHECK(assassin.coins() == 1);
	CHECK_NOTHROW(assassin.foreign_aid());
	CHECK(assassin.coins() == 3);
	CHECK(game.turn() == "David");
	CHECK(captain.coins() == 1);
	CHECK_NOTHROW(captain.foreign_aid());
	CHECK(captain.coins() == 3);
    CHECK(game.turn() == "Roni");
    CHECK(ambassador.coins() == 1);
	CHECK_NOTHROW(ambassador.foreign_aid());
	CHECK(ambassador.coins() == 3);

    // end of round 2
}