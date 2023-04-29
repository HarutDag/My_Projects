#include <iostream>

struct Taracq
{
	int x = 0;
	int y = 0;
};

class Xot
{
	int count;

public:

	Xot(int count = 0)
	{
		this->count = count;
	}

	void qchacum(int kerav)
	{
		if (count >= kerav)
			count -= kerav;
		else std::cout << "Xoty qchutyun arec!";
	}
};

class Arev // 1 or
{
	int energia; // amen pahi, energian hamarenq nuyn chapi

	struct Jamanaki_miavor // jam
	{
		int jam;
		int cerek;
		int gisher;
		int max_jam;
	} mek_or;

public:

	Arev(int x = 6, int y = 21)
	{

		mek_or.cerek = x; // vor jamica cerek, voric gisher
		mek_or.gisher = y;
		mek_or.jam = x;
		mek_or.max_jam = 24;
		energia = x * 10; // cerekva mek jamum arevi << tvac >> energian fotonneri mijocov
	}

	int get_energia()
	{
		return energia;
	}

	int& get_jam()
	{
		return mek_or.jam;
	}

	int get_cerek()
	{
		return mek_or.cerek;
	}

	int get_gisher()
	{
		return mek_or.gisher;
	}

	int get_max_jam()
	{
		return mek_or.max_jam;
	}
};

class Car
{
	int odi_artadrutyun;

public:

	Car()
	{
		odi_artadrutyun = 0;
	}
	Car(Arev arev)
	{
		odi_artadrutyun = arev.get_energia() * 100; // mek jamum cari artadrac << miavor >> ody
	}
	int artadrutyun()
	{
		return odi_artadrutyun;
	}
};

class Mijavayr
{
	Xot xot;
	Taracq taracq;
	Arev arev;
	Car car;
	int od;

public:

	Mijavayr(int x = 100, int y = 100, int cerek = 6, int gisher = 21) : xot(y* x * 10), arev(cerek, gisher), car(arev)
	{
		taracq.x = x;
		std::cout << "Taracqi erkarutyuny havasar e " << x << " -i\n";
		taracq.y = y;
		std::cout << "Taracqi laynutyuny havasar e " << y << " -i\n";
		od = 0;
	}

	void show_chaps()
	{
		std::cout << "x = " << taracq.x << "\ty = " << taracq.y << '\n';
	}

	int get_x()
	{
		return taracq.x;
	}

	int get_y()
	{
		return taracq.y;
	}

	Xot& get_xot()
	{
		return xot;
	}

	Arev& get_arev()
	{
		return arev;
	}

	Car& get_car()
	{
		return car;
	}

	int& get_od()
	{
		return od;
	}
};

class Dirq
{
	int x;
	int y;

public:

	Dirq(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
		std::cout << "Object -i kordinatnern en " << x << " . " << y << " -y\n";
	}

	void popoxutyun(Mijavayr getin, int x, int y)
	{
		if (getin.get_x() >= x && getin.get_y() >= y)
		{
			this->x = x;
			this->y = y;
			std::cout << "Object -i kordinatnern en " << x << " . " << y << " -y\n";
		}
		else if (x < 0 || y < 0)
			std::cout << "Taracqn anhasaneli e!\n";
		else
		{
			std::cout << "Taracqn anhasaneli e!\n";
		}
	}

	int get_x()
	{
		return x;
	}

	int get_y()
	{
		return y;
	}
};

class Gort
{
	int axorjak; // ereq jamum caxsac xoti qanak
	int sovacutyun;
	int shncharutyun; // mek jamum caxsac ttvacni cavaly
	Mijavayr getin;
	Dirq dirq;
	int orer;

public:

	Gort(int axorjak = 12, int shncharutyun = 50, int x = 50, int y = 50) : getin(x * 4, y * 4), dirq(x, y)
	{
		show_dirq();
		this->axorjak = axorjak;
		this->shncharutyun = shncharutyun;
		sovacutyun = 0;
	}

	void utel()
	{
		if (sovacutyun)
		{
			std::cout << "nyam - nyam\n";
			getin.get_xot().qchacum(sovacutyun * (axorjak / 3)); // hamarenq utely tevum e mek jam, ankax sovacutyan astijanic
			getin.get_od() = getin.get_car().artadrutyun() - shncharutyun;
			if (getin.get_arev().get_jam() < getin.get_arev().get_max_jam() - 1)
				++getin.get_arev().get_jam();
			else
				getin.get_arev().get_jam() = 0;
			sovacutyun = 0;
		}
		else
		{
			std::cout << "Gorty sovac che!\n";
		}
	}

	void qnel()
	{
		std::cout << "Jamy " << getin.get_arev().get_jam() << " -n e\n";
		if (getin.get_arev().get_cerek() <= getin.get_arev().get_jam() && getin.get_arev().get_jam() < getin.get_arev().get_gisher())
		{
			std::cout << "Der gisher che!\n";
		}
		else
		{
			std::cout << "zZz zZz\n";
			getin.get_arev().get_jam() = getin.get_arev().get_cerek();
		}
	}

	void show_dirq()
	{
		std::cout << "Gorty gtnvum e " << dirq.get_x() << " . " << dirq.get_y() << " dirqum\n";
	}

	void show_taracq()
	{
		getin.show_chaps();
	}

	void texasharjvel(int x, int y)
	{
		int tevoxutyun = 0;

		if (dirq.get_x() <= x && dirq.get_y() <= y)
		{
			if (x >= y)
			{
				tevoxutyun = x / 10; // mek jamum, gorty karox e ancnel 10 miavor dirqerov

				while (tevoxutyun)
				{
					if (getin.get_arev().get_jam() < getin.get_arev().get_max_jam() - 1)
						++getin.get_arev().get_jam();
					else
						getin.get_arev().get_jam() = 0;
					std::cout << "trichq - trichq\n";

					getin.get_od() = getin.get_car().artadrutyun() - shncharutyun;
					++sovacutyun;
					if (sovacutyun >= 3)
					{
						utel();
					}
					if (getin.get_arev().get_jam() >= getin.get_arev().get_gisher())
					{
						qnel();
					}
					--tevoxutyun;
				}
			}
			else
			{
				tevoxutyun = y / 10;

				while (tevoxutyun)
				{
					if (getin.get_arev().get_jam() < getin.get_arev().get_max_jam() - 1)
						++getin.get_arev().get_jam();
					else
						getin.get_arev().get_jam() = 0;
					std::cout << "trichq - trichq\n";

					getin.get_od() = getin.get_car().artadrutyun() - shncharutyun;
					++sovacutyun;
					if (sovacutyun >= 3)
					{
						utel();
					}
					if (getin.get_arev().get_jam() >= getin.get_arev().get_gisher())
					{
						qnel();
					}
					--tevoxutyun;
				}
			}

			dirq.popoxutyun(getin, x, y);
		}
		else if (dirq.get_x() <= x && dirq.get_y() >= y)
		{
			if (x >= dirq.get_y() - y)
			{
				tevoxutyun = x / 10;

				while (tevoxutyun)
				{
					if (getin.get_arev().get_jam() < getin.get_arev().get_max_jam() - 1)
						++getin.get_arev().get_jam();
					else
						getin.get_arev().get_jam() = 0;
					std::cout << "trichq - trichq\n";

					getin.get_od() = getin.get_car().artadrutyun() - shncharutyun;
					++sovacutyun;
					if (sovacutyun >= 3)
					{
						utel();
					}
					if (getin.get_arev().get_jam() >= getin.get_arev().get_gisher())
					{
						qnel();
					}
					--tevoxutyun;
				}
			}
			else
			{
				tevoxutyun = (dirq.get_y() - y) / 10;

				while (tevoxutyun)
				{
					if (getin.get_arev().get_jam() < getin.get_arev().get_max_jam() - 1)
						++getin.get_arev().get_jam();
					else
						getin.get_arev().get_jam() = 0;
					std::cout << "trichq - trichq\n";

					getin.get_od() = getin.get_car().artadrutyun() - shncharutyun;
					++sovacutyun;
					if (sovacutyun >= 3)
					{
						utel();
					}
					if (getin.get_arev().get_jam() >= getin.get_arev().get_gisher())
					{
						qnel();
					}
					--tevoxutyun;
				}
			}
		}
		else if (dirq.get_x() >= x && dirq.get_y() <= y)
		{
			if (dirq.get_x() - x >= y)
			{
				tevoxutyun = (dirq.get_x() - x) / 10;

				while (tevoxutyun)
				{
					if (getin.get_arev().get_jam() < getin.get_arev().get_max_jam() - 1)
						++getin.get_arev().get_jam();
					else
						getin.get_arev().get_jam() = 0;
					std::cout << "trichq - trichq\n";

					getin.get_od() = getin.get_car().artadrutyun() - shncharutyun;
					++sovacutyun;
					if (sovacutyun >= 3)
					{
						utel();
					}
					if (getin.get_arev().get_jam() >= getin.get_arev().get_gisher())
					{
						qnel();
					}
					--tevoxutyun;
				}
			}
			else
			{
				tevoxutyun = y / 10;

				while (tevoxutyun)
				{
					if (getin.get_arev().get_jam() < getin.get_arev().get_max_jam() - 1)
						++getin.get_arev().get_jam();
					else
						getin.get_arev().get_jam() = 0;
					std::cout << "trichq - trichq\n";

					getin.get_od() = getin.get_car().artadrutyun() - shncharutyun;
					++sovacutyun;
					if (sovacutyun >= 3)
					{
						utel();
					}
					if (getin.get_arev().get_jam() >= getin.get_arev().get_gisher())
					{
						qnel();
					}
					--tevoxutyun;
				}
			}
		}
		else
		{
			if (dirq.get_x() - x >= dirq.get_y() - y)
			{
				tevoxutyun = (dirq.get_x() - x) / 10;

				while (tevoxutyun)
				{
					if (getin.get_arev().get_jam() < getin.get_arev().get_max_jam() - 1)
						++getin.get_arev().get_jam();
					else
						getin.get_arev().get_jam() = 0;
					std::cout << "trichq - trichq\n";

					getin.get_od() = getin.get_car().artadrutyun() - shncharutyun;
					++sovacutyun;
					if (sovacutyun >= 3)
					{
						utel();
					}
					if (getin.get_arev().get_jam() >= getin.get_arev().get_gisher())
					{
						qnel();
					}
					--tevoxutyun;
				}
			}
			else
			{
				tevoxutyun = (dirq.get_y() - y) / 10;

				while (tevoxutyun)
				{
					if (getin.get_arev().get_jam() < getin.get_arev().get_max_jam() - 1)
						++getin.get_arev().get_jam();
					else
						getin.get_arev().get_jam() = 0;
					std::cout << "trichq - trichq\n";

					getin.get_od() = getin.get_car().artadrutyun() - shncharutyun;
					++sovacutyun;
					if (sovacutyun >= 3)
					{
						utel();
					}
					if (getin.get_arev().get_jam() >= getin.get_arev().get_gisher())
					{
						qnel();
					}
					--tevoxutyun;
				}
			}

			dirq.popoxutyun(getin, x, y);
		}
	}
};

int main()
{
	Gort gort;

	int func = 777;

	std::cout << "Barev hargeli ynker. Du gtnvum es << Gort >> -i cragrum ev karox es voroshakioren karavarel nran\n"
		<< "Sexmir 1, vorpeszi gorty snvi\n" << "Sexmir 2, vorpeszi gorty qni\n"
		<< "Sexmir 3, nshir kordinatner ( x ev y ), ev texasharjir gortin\n\n"
		<< "Cragric durs galu hamar sexmel 0\n";

	while (func)
	{
		std::cin >> func;

		if (func == 1)
		{
			gort.utel();
		}
		else if (func == 2)
		{
			gort.qnel();
		}
		else if (func == 3)
		{
			std::cout << "Mijavayri minimal ev maqsimal kordinatnern en, hamapatasxanabar\n"
				<< "0 . 0\n";
			gort.show_taracq();

			gort.show_dirq();

			int x = 0,
				y = 0;

			std::cin >> x >> y;

			gort.texasharjvel(x, y);
		}
		else if (func)
		{
			std::cout << "Ayspisi hraman goyutyun shuni. Xndrum em veranayel paymannery\n"
				<< "Sexmir 1, vorpeszi gorty snvi\n" << "Sexmir 2, vorpeszi gorty qni\n"
				<< "Sexmir 3, nshir kordinatner ( x ev y ), ev texasharjir gortin\n\n"
				<< "Cragric durs galu hamar sexmel 0\n";
		}
	}

	return 0;
}