#include <show_field.h>
#include <2darray.h>

int main()
{
	int x, y;
	char map_data[] = {
		11, 13, 1, 1, 3, 
		8, 5, 2, 10, 10, 
		12, 3, 14, 10, 14, 
		13, 6, 13, 0, 3, 
		13, 5, 5, 6, 14,
		};
	char grids_data[] = {
		0, 1, 1, 1, 1, 
		0, 2, 1, 1, 1, 
		1, 1, 1, 1, 1, 
		1, 1, 1, 1, 1, 
		1, 1, 1, 1, 1, 
		};

	_2DArray *map, *grids;

	map = make_2DArray(5, 5);
	for(y = 0; y < 5; y++) {
		for(x = 0; x < 5; x++) {
			set_2DArray(map, x, y, map_data[x + y * 5]);
		}
	}

	grids = make_2DArray(5, 5);
	for(y = 0; y < 5; y++) {
		for(x = 0; x < 5; x++) {
			set_2DArray(grids, x, y, grids_data[x + y * 5]);
		}
	}
	
	show_field(map, grids);
	/*
		こうなるはず

		+-+-------+
		| |. . . .|
		| +-o o o |
		|  @ .|.|.|
		| o-+ | | |
		|. .|.|.|.|
		+-o +-+ +-+
		|. .|. . .|
		+---+-o o |
		|. . . .|.|
		+-------+-+
	*/

	delete_2DArray(map);
	delete_2DArray(grids);

	return 0;
}
