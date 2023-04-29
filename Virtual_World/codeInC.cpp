//#include <iostream>
#include <stdio.h>

struct Taracq
{
	int x = 0;
	int y = 0;
};

struct Xot
{
	int count = 0;
};

Xot Xot_Initializer(Xot* This, int count = 0)
{
	This->count = count;

	return *This;
}

void qchacum(Xot* This, int kerav)
{
	if (This->count >= kerav)
		This->count -= kerav;
	else
		printf("Xoty qchutyun arec!");
}

struct Arev // 1 or
{
	int energia = 0; // amen pahi, energian hamarenq nuyn chapi

	struct Jamanaki_miavor // jam
	{
		int jam = 0;
		int cerek = 0;
		int gisher = 0;
		int max_jam = 0;
	} mek_or;
};

Arev Arev_Initializer(Arev* This, int x = 6, int y = 21)
{
	This->mek_or.cerek = x; // vor jamica cerek, voric gisher
	This->mek_or.gisher = y;
	This->mek_or.jam = x;
	This->mek_or.max_jam = 24;
	This->energia = x * 10; // cerekva mek jamum arevi << tvac >> energian fotonneri mijocov

	return *This;
}

int get_energia(const Arev* This)
{
	return This->energia;
}

int& get_jam(Arev* This)
{
	return This->mek_or.jam;
}

int get_cerek(const Arev* This)
{
	return This->mek_or.cerek;
}

int get_gisher(const Arev* This)
{
	return This->mek_or.gisher;
}

int get_max_jam(const Arev* This)
{
	return This->mek_or.max_jam;
}

struct Car
{
	int odi_artadrutyun = 0;
};

Car Car_Initializer(Car* This)
{
	This->odi_artadrutyun = 0;

	return *This;
}

Car Car_Constructor(Car* This, const Arev arev)
{
	This->odi_artadrutyun = get_energia(&arev) * 100; // mek jamum cari artadrac << miavor >> ody
	
	return *This;
}

int artadrutyun(const Car* This)
{
	return This->odi_artadrutyun;
}

struct Mijavayr
{
	Xot xot;
	Taracq taracq;
	Arev arev;
	Car car;
	int od = 0;
};

Mijavayr Mijavayr_Initializer(Mijavayr* This, int x = 100, int y = 100, int cerek = 6, int gisher = 21)
{
	Xot_Initializer(&This->xot, y * x * 10);
	Arev_Initializer(&This->arev, cerek, gisher);
	Car_Constructor(&This->car, This->arev);
	This->taracq.x = x;
	printf("Taracqi erkarutyuny havasar e ");
	printf("%i", x);
	printf(" -i\n");
	This->taracq.y = y;
	printf("Taracqi laynutyuny havasar e ");
	printf("%i", y);
	printf(" -i\n");
	This->od = 0;

	return *This;
}

void show_chaps(const Mijavayr* This)
{
	printf("x = ");
	printf("%i", This->taracq.x);
	printf("\ty = ");
	printf("%i", This->taracq.y);
	printf("\n");
}

int get_x(const Mijavayr* This)
{
	return This->taracq.x;
}

int get_y(const Mijavayr* This)
{
	return This->taracq.y;
}

Xot& get_xot(Mijavayr* This)
{
	return This->xot;
}

Arev& get_arev(Mijavayr* This)
{
	return This->arev;
}

Car& get_car(Mijavayr* This)
{
	return This->car;
}

int& get_od(Mijavayr* This)
{
	return This->od;
}

struct Dirq
{
	int x = 0;
	int y = 0;
};

Dirq Dirq_Initializer(Dirq* This, int x = 0, int y = 0)
{
	This->x = x;
	This->y = y;
	printf("Object -i kordinatnern en ");
	printf("%i", This->x);
	printf(" . ");
	printf("%i", This->y);
	printf(" -y\n");

	return *This;
}

void popoxutyun(Dirq* This, const Mijavayr getin, int x, int y)
{
	if (get_x(&getin) >= x && get_y(&getin) >= y)
	{
		This->x = x;
		This->y = y;
		printf("Object -i kordinatnern en ");
		printf("%i", This->x);
		printf(" . ");
		printf("%i", This->y);
		printf(" -y\n");
	}
	else if (x < 0 || y < 0)
		printf("Taracqn anhasaneli e!\n");
	else
		printf("Taracqn anhasaneli e!\n");
}

int get_Dirq_x(Dirq* This)
{
	return This->x;
}

int get_Dirq_y(Dirq* This)
{
	return This->y;
}

struct Gort
{
	int axorjak = 0; // ereq jamum caxsac xoti qanak
	int sovacutyun = 0;
	int shncharutyun = 0; // mek jamum caxsac ttvacni cavaly
	Mijavayr getin;
	Dirq dirq;
	int orer = 0;
};

void show_dirq(Gort* This)
{
	printf("Gorty gtnvum e ");
	printf("%i", get_Dirq_x(&This->dirq));
	printf(" . ");
	printf("%i", get_Dirq_y(&This->dirq));
	printf(" dirqum\n");
}

Gort Gort_Initializer(Gort* This, int axorjak = 12, int shncharutyun = 50, int x = 50, int y = 50)
{
	Mijavayr_Initializer(&This->getin, x * 4, y * 4);
	Dirq_Initializer(&This->dirq, x, y);
	show_dirq(This);
	This->axorjak = axorjak;
	This->shncharutyun = shncharutyun;
	This->sovacutyun = 0;

	return *This;
}

void utel(Gort* This)
{
	if (This->sovacutyun)
	{
		printf("nyam - nyam\n");
		qchacum(&get_xot(&This->getin), This->sovacutyun * (This->axorjak / 3)); // hamarenq utely tevum e mek jam, ankax sovacutyan astijanic
		get_od(&This->getin) = artadrutyun(&get_car(&This->getin)) - This->shncharutyun;
		if (get_jam(&get_arev(&This->getin)) < get_max_jam(&get_arev(&This->getin)) - 1)
			++get_jam(&get_arev(&This->getin));
		else
			get_jam(&get_arev(&This->getin)) = 0;
		This->sovacutyun = 0;
	}
	else
	{
		printf("Gorty sovac che!\n");
	}
}

void qnel(Gort* This)
{
	printf("Jamy ");
	printf("%i", get_jam(&get_arev(&This->getin)));
	printf(" -n e\n");

	if (get_cerek(&get_arev(&This->getin)) <= get_jam(&get_arev(&This->getin)) && get_jam(&get_arev(&This->getin)) < get_gisher(&get_arev(&This->getin)))
	{
		printf("Der gisher che!\n");
	}
	else
	{
		printf("zZz zZz\n");
		get_jam(&get_arev(&This->getin)) = get_cerek(&get_arev(&This->getin));
	}
}

void show_taracq(Gort* This)
{
	show_chaps(&This->getin);
}

void texasharjvel(Gort* This, int x, int y)
{
	int tevoxutyun = 0;

	if (get_Dirq_x(&This->dirq) <= x && get_Dirq_y(&This->dirq) <= y)
	{
		if (x >= y)
		{
			tevoxutyun = x / 10; // mek jamum, gorty karox e ancnel 10 miavor dirqerov

			while (tevoxutyun)
			{
				if (get_jam(&get_arev(&This->getin)) < get_max_jam(&get_arev(&This->getin)) - 1)
					++get_jam(&get_arev(&This->getin));
				else
					get_jam(&get_arev(&This->getin)) = 0;
				printf("trichq - trichq\n");

				get_od(&This->getin) = artadrutyun(&get_car(&This->getin)) - This->shncharutyun;
				++This->sovacutyun;
				if (This->sovacutyun >= 3)
				{
					utel(This);
				}
				if (get_jam(&get_arev(&This->getin)) >= get_gisher(&get_arev(&This->getin)))
				{
					qnel(This);
				}
				--tevoxutyun;
			}
		}
		else
		{
			tevoxutyun = y / 10;

			while (tevoxutyun)
			{
				if (get_jam(&get_arev(&This->getin)) < get_max_jam(&get_arev(&This->getin)) - 1)
					++get_jam(&get_arev(&This->getin));
				else
					get_jam(&get_arev(&This->getin)) = 0;
				printf("trichq - trichq\n");

				get_od(&This->getin) = artadrutyun(&get_car(&This->getin)) - This->shncharutyun;
				++This->sovacutyun;
				if (This->sovacutyun >= 3)
				{
					utel(This);
				}
				if (get_jam(&get_arev(&This->getin)) >= get_gisher(&get_arev(&This->getin)))
				{
					qnel(This);
				}
				--tevoxutyun;
			}
		}

		popoxutyun(&This->dirq, This->getin, x, y);
	}
	else if (get_Dirq_x(&This->dirq) <= x && get_Dirq_y(&This->dirq) >= y)
	{
		if (x >= get_Dirq_y(&This->dirq) - y)
		{
			tevoxutyun = x / 10;

			while (tevoxutyun)
			{
				if (get_jam(&get_arev(&This->getin)) < get_max_jam(&get_arev(&This->getin)) - 1)
					++get_jam(&get_arev(&This->getin));
				else
					get_jam(&get_arev(&This->getin)) = 0;
				printf("trichq - trichq\n");

				get_od(&This->getin) = artadrutyun(&get_car(&This->getin)) - This->shncharutyun;
				++This->sovacutyun;
				if (This->sovacutyun >= 3)
				{
					utel(This);
				}
				if (get_jam(&get_arev(&This->getin)) >= get_gisher(&get_arev(&This->getin)))
				{
					qnel(This);
				}
				--tevoxutyun;
			}
		}
		else
		{
			tevoxutyun = (get_Dirq_y(&This->dirq) - y) / 10;

			while (tevoxutyun)
			{
				if (get_jam(&get_arev(&This->getin)) < get_max_jam(&get_arev(&This->getin)) - 1)
					++get_jam(&get_arev(&This->getin));
				else
					get_jam(&get_arev(&This->getin)) = 0;
				printf("trichq - trichq\n");

				get_od(&This->getin) = artadrutyun(&get_car(&This->getin)) - This->shncharutyun;
				++This->sovacutyun;
				if (This->sovacutyun >= 3)
				{
					utel(This);
				}
				if (get_jam(&get_arev(&This->getin)) >= get_gisher(&get_arev(&This->getin)))
				{
					qnel(This);
				}
				--tevoxutyun;
			}
		}

		popoxutyun(&This->dirq, This->getin, x, y);
	}
	else if (get_Dirq_x(&This->dirq) >= x && get_Dirq_y(&This->dirq) <= y)
	{
		if (get_Dirq_x(&This->dirq) - x >= y)
		{
			tevoxutyun = (get_Dirq_x(&This->dirq) - x) / 10;

			while (tevoxutyun)
			{
				if (get_jam(&get_arev(&This->getin)) < get_max_jam(&get_arev(&This->getin)) - 1)
					++get_jam(&get_arev(&This->getin));
				else
					get_jam(&get_arev(&This->getin)) = 0;
				printf("trichq - trichq\n");

				get_od(&This->getin) = artadrutyun(&get_car(&This->getin)) - This->shncharutyun;
				++This->sovacutyun;
				if (This->sovacutyun >= 3)
				{
					utel(This);
				}
				if (get_jam(&get_arev(&This->getin)) >= get_gisher(&get_arev(&This->getin)))
				{
					qnel(This);
				}
				--tevoxutyun;
			}
		}
		else
		{
			tevoxutyun = y / 10;

			while (tevoxutyun)
			{
				if (get_jam(&get_arev(&This->getin)) < get_max_jam(&get_arev(&This->getin)) - 1)
					++get_jam(&get_arev(&This->getin));
				else
					get_jam(&get_arev(&This->getin)) = 0;
				printf("trichq - trichq\n");

				get_od(&This->getin) = artadrutyun(&get_car(&This->getin)) - This->shncharutyun;
				++This->sovacutyun;
				if (This->sovacutyun >= 3)
				{
					utel(This);
				}
				if (get_jam(&get_arev(&This->getin)) >= get_gisher(&get_arev(&This->getin)))
				{
					qnel(This);
				}
				--tevoxutyun;
			}
		}

		popoxutyun(&This->dirq, This->getin, x, y);
	}
	else
	{
		if (get_Dirq_x(&This->dirq) - x >= get_Dirq_y(&This->dirq) - y)
		{
			tevoxutyun = (get_Dirq_x(&This->dirq) - x) / 10;

			while (tevoxutyun)
			{
				if (get_jam(&get_arev(&This->getin)) < get_max_jam(&get_arev(&This->getin)) - 1)
					++get_jam(&get_arev(&This->getin));
				else
					get_jam(&get_arev(&This->getin)) = 0;
				printf("trichq - trichq\n");

				get_od(&This->getin) = artadrutyun(&get_car(&This->getin)) - This->shncharutyun;
				++This->sovacutyun;
				if (This->sovacutyun >= 3)
				{
					utel(This);
				}
				if (get_jam(&get_arev(&This->getin)) >= get_gisher(&get_arev(&This->getin)))
				{
					qnel(This);
				}
				--tevoxutyun;
			}
		}
		else
		{
			tevoxutyun = (get_Dirq_y(&This->dirq) - y) / 10;

			while (tevoxutyun)
			{
				if (get_jam(&get_arev(&This->getin)) < get_max_jam(&get_arev(&This->getin)) - 1)
					++get_jam(&get_arev(&This->getin));
				else
					get_jam(&get_arev(&This->getin)) = 0;
				printf("trichq - trichq\n");

				get_od(&This->getin) = artadrutyun(&get_car(&This->getin)) - This->shncharutyun;
				++This->sovacutyun;
				if (This->sovacutyun >= 3)
				{
					utel(This);
				}
				if (get_jam(&get_arev(&This->getin)) >= get_gisher(&get_arev(&This->getin)))
				{
					qnel(This);
				}
				--tevoxutyun;
			}
		}

		popoxutyun(&This->dirq, This->getin, x, y);
	}
}


int main()
{
	Gort gort = Gort_Initializer(&gort);

	int func = 777;

	printf("Barev hargeli ynker. Du gtnvum es << Gort >> -i cragrum ev karox es voroshakioren karavarel nran\nSexmir 1, vorpeszi gorty snvi\nSexmir 2, vorpeszi gorty qni\nSexmir 3, nshir kordinatner ( x ev y ), ev texasharjir gortin\n\nCragric durs galu hamar sexmel 0\n");

	while (func)
	{
		scanf("%i", &func);

		if (func == 1)
		{
			utel(&gort);
		}
		else if (func == 2)
		{
			qnel(&gort);
		}
		else if (func == 3)
		{
			printf("Mijavayri minimal ev maqsimal kordinatnern en, hamapatasxanabar\n0 . 0\n");
			show_taracq(&gort);

			show_dirq(&gort);

			int x = 0,
				y = 0;

			scanf("%i", &x);
			scanf("%i", &y);

			texasharjvel(&gort, x, y);
		}
		else if (func)
		{
			printf("Ayspisi hraman goyutyun shuni. Xndrum em veranayel paymannery\nSexmir 1, vorpeszi gorty snvi\nSexmir 2, vorpeszi gorty qni\nSexmir 3, nshir kordinatner ( x ev y ), ev texasharjir gortin\n\nCragric durs galu hamar sexmel 0\n");
		}
	}

	return 0;
}