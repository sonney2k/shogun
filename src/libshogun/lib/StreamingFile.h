/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Shashwat Lal Das
 * Copyright (C) 2011 Berlin Institute of Technology and Max-Planck-Society
 */
#ifndef __STREAMING_FILE_H__
#define __STREAMING_FILE_H__

#include "lib/config.h"
#include "base/DynArray.h"
#include "lib/common.h"
#include "lib/File.h"
#include "lib/io.h"
#include "lib/DataType.h"
#include <ctype.h>

namespace shogun
{
/** @brief A Streaming File access class.
 *
 * - Vectors are read as one vector per line
 * - NOT YET IMPLEMENTED:
 * - Matrices are written out as one column per line
 * - Sparse Matrices are written out as one column per line (libsvm/svmlight
 *	 style format)
 * - Strings are written out as one string per line
 *
 */
	class CStreamingFile: public CSGObject
	{
	public:
		/** default constructor	 */
		CStreamingFile();

		/** constructor
		 *
		 * @param f already opened file
		 * @param name variable name (e.g. "x" or "/path/to/x")
		 */
		CStreamingFile(FILE* f, const char* name=NULL);

		/** constructor
		 *
		 * @param fname filename to open
		 * @param rw mode, 'r' or 'w'
		 */
		CStreamingFile(char* fname, char rw='r');

		/** default destructor */
		virtual ~CStreamingFile();

		/**
		 * Closes the file
		 */
		void close()
		{
			SG_FREE(filename);
			if (file)
				fclose(file);
			filename=NULL;
			file=NULL;
		}

		/** @name Dense Vector Access Functions
		 *
		 * Functions to access dense vectors of one of several
		 * base data types.  These functions are used when
		 * reading one dense vector at a time from an input
		 * source and return the vector and length of the
		 * vector by reference.
		 */
		//@{
		virtual void get_vector(bool*& vector, int32_t& len);
		virtual void get_vector(uint8_t*& vector, int32_t& len);
		virtual void get_vector(char*& vector, int32_t& len);
		virtual void get_vector(int32_t*& vector, int32_t& len);
		virtual void get_vector(float32_t*& vector, int32_t& len);
		virtual void get_vector(float64_t*& vector, int32_t& len);
		virtual void get_vector(int16_t*& vector, int32_t& len);
		virtual void get_vector(uint16_t*& vector, int32_t& len);
		virtual void get_vector(int8_t*& vector, int32_t& len);
		virtual void get_vector(uint32_t*& vector, int32_t& len);
		virtual void get_vector(int64_t*& vector, int32_t& len);
		virtual void get_vector(uint64_t*& vector, int32_t& len);
		virtual void get_vector(floatmax_t*& vector, int32_t& len);
		//@}

		/** @name Dense Vector And Label Access Functions
		 *
		 * Functions to access dense vectors of one of several
		 * base data types.  These functions are used when
		 * reading one dense vector at a time from an input
		 * source and return the vector, length and label of
		 * the vector by reference.
		 */
		//@{
		virtual void get_vector_and_label
			(bool*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(uint8_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(char*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(int32_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(float32_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(float64_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(int16_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(uint16_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(int8_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(uint32_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(int64_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(uint64_t*& vector, int32_t& len, float64_t& label);
		virtual void get_vector_and_label
			(floatmax_t*& vector, int32_t& len, float64_t& label);
		//@}

		/** @name String Access Functions
		 *
		 * Functions to access string of one of several base
		 * data types. These functions are used when reading
		 * one string vector at a time from an input source
		 * and return the vector and length of the vector by
		 * reference.
		 */
		//@{
		virtual void get_string(bool*& vector, int32_t& len);
		virtual void get_string(uint8_t*& vector, int32_t& len);
		virtual void get_string(char*& vector, int32_t& len);
		virtual void get_string(int32_t*& vector, int32_t& len);
		virtual void get_string(float32_t*& vector, int32_t& len);
		virtual void get_string(float64_t*& vector, int32_t& len);
		virtual void get_string(int16_t*& vector, int32_t& len);
		virtual void get_string(uint16_t*& vector, int32_t& len);
		virtual void get_string(int8_t*& vector, int32_t& len);
		virtual void get_string(uint32_t*& vector, int32_t& len);
		virtual void get_string(int64_t*& vector, int32_t& len);
		virtual void get_string(uint64_t*& vector, int32_t& len);
		virtual void get_string(floatmax_t*& vector, int32_t& len);
		//@}

		/** @name String And Label Access Functions
		 *
		 * Functions to access strings of one of several
		 * base data types. These functions are used when
		 * reading one string vector at a time from an input
		 * source and return the vector, length and label of the
		 * vector by reference.
		 */
		//@{
		virtual void get_string_and_label
			(bool*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(uint8_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(char*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(int32_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(float32_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(float64_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(int16_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(uint16_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(int8_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(uint32_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(int64_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(uint64_t*& vector, int32_t& len, float64_t& label);
		virtual void get_string_and_label
			(floatmax_t*& vector, int32_t& len, float64_t& label);
		//@}

		/** @name Sparse Vector Access Functions
		 *
		 * Functions to access sparse vectors of one of
		 * several base data types. These functions are used
		 * when reading one sparse vector at a time from an
		 * input source and return the vector and length of
		 * the vector by reference.
		 */
		//@{
		virtual void get_sparse_vector
			(SGSparseVectorEntry<bool>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<uint8_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<char>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<int32_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<float32_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<float64_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<int16_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<uint16_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<int8_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<uint32_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<int64_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<uint64_t>*& vector, int32_t& len);
		virtual void get_sparse_vector
			(SGSparseVectorEntry<floatmax_t>*& vector, int32_t& len);
		//@}

		/** @name Sparse Vector And Label Access Functions
		 *
		 * Functions to access sparse vectors of one of
		 * several base data types.  These functions are used
		 * when reading one sparse vector at a time from an
		 * input source and return the vector, length and
		 * label of the vector by reference.
		 */
		//@{
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<bool>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<uint8_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<char>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<int32_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<float32_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<float64_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<int16_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<uint16_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<int8_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<uint32_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<int64_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<uint64_t>*& vector, int32_t& len, float64_t& label);
		virtual void get_sparse_vector_and_label
			(SGSparseVectorEntry<floatmax_t>*& vector, int32_t& len, float64_t& label);
		//@}

		/** @return object name */
		inline virtual const char* get_name() const { return "StreamingFile"; }

	protected:
		/// File object
		FILE* file;
		/// Task
		char task;
		/// Name of the handled file
		char* filename;

	};
}
#endif //__STREAMING_FILE_H__
