#include <iostream>
#include <unistd.h>
#include <chrono>

#define MS_PER_UPDATE 33


using namespace std;
using ms = chrono::milliseconds;
using get_time = chrono::steady_clock;


int main()
{
	auto last_ts = std::chrono::duration_cast<ms>(get_time::now().time_since_epoch()).count();
	int lag = 0;

	cout << "Game start\n";
	for (;;) {
		/* Time handling */
		auto curr_ts = std::chrono::duration_cast<ms>(get_time::now().time_since_epoch()).count();
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