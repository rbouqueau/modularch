/*
 *			Authors: Romain Bouqueau 
 *			Copyright (c) Romain Bouqueau 2013
 *					All rights reserved
 *
 *  This file is part of Modularch
 *
 *  GPAC is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2.
 *   
 *  GPAC is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *   
 *  You should have received a copy of the GNU General Public
 *  License along with this library; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
 *
 */

#ifndef _MODULARCH_DATA_HPP_
#define _MODULARCH_DATA_HPP_

#include <cstdint>


namespace ModulArch {

/**
 * A generic data container.
 * Ownership is transferred to this container.
 */
template<typename T>
class Data {
public:
	Data(uint8_t *data, uint64_t size, void (*deleter)(T*), T *deletee)
		: data(data), size(size), deleter(deleter), deletee(deletee) {
	}

	~Data() {
		deleter(deletee);
	}

private:
	Data();

	uint8_t *data;
	uint64_t size;

	//TODO: use unique_ptr instead
	void (*deleter)(T*);
	T *deletee;
};

}

#endif