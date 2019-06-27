#include <iostream>
#include <unistd.h>
#include <chrono>

#define UPDATE_RATE   30 // Hz
#define MS_PER_UPDATE (1000 / UPDATE_RATE)


using namespace std;
using ms = chrono::milliseconds;
using get_time = chrono::steady_clock;


int main()
{
	auto last_ts = chrono::duration_cast<ms>(get_time::now().time_since_epoch()).count();
	int lag = 0;

	cout << "Game start\n";
	cout << "game update rate = "<<UPDATE_RATE<<" ("<<MS_PER_UPDATE<<"ms per update)\n";

	for (;;) {
		/* Time handling */
		auto curr_ts = chrono::duration_cast<ms>(get_time::now().time_since_epoch()).count();
		lag += (curr_ts - last_ts);
		last_ts = curr_ts;

		/* Process input */
		while (lag >= MS_PER_UPDATE) {
			/* Update game state */
			cout << "Update game\n";

			lag -= MS_PER_UPDATE;
		}

		/* Render */
	}

	return 0;
}