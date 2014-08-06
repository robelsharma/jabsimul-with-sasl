#include <openssl/bio.h>
#include <openssl/evp.h>


unsigned char *do_base64_encode(unsigned char *data, int len, int *lenoutput)
{

	// bio is simply a class that wraps BIO* and it free the BIO in the destructor.

	BIO *b64 = BIO_new(BIO_f_base64()); // create BIO to perform base64
	BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

	BIO *mem = BIO_new(BIO_s_mem()); // create BIO that holds the result

	// chain base64 with mem, so writing to b64 will encode base64 and write to mem.
	BIO_push(b64, mem);

	// write data
	int done = 0;
	int res = 0;
	while(!done)
	{
		res = BIO_write(b64, data, len);

		if(res <= 0) // if failed
		{
		    if(BIO_should_retry(b64)){
		        continue;
		    }
		    else // encoding failed
		    {
		        /* Handle Error!!! */
		    }
		}
		else // success!
		    done = 1;
	}

	BIO_flush(b64);

	// get a pointer to mem's data
	unsigned char* output;
	*lenoutput = BIO_get_mem_data(mem, &output);

	// assign data to output
	//std::string s(dt, len2);

	return output;

}

/*
* Added by Robel Sharma
* Dhaka Bangladesh
*/
