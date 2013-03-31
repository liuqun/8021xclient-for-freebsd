#define NDEBUG
#include <assert.h>
#include <stdio.h>
#include <libnet.h>
void DoMyWork(libnet_t *handle);
void DoMyWork(libnet_t *handle)
{
	struct libnet_ether_addr *p = NULL;
	assert(handle != NULL);

	p = libnet_get_hwaddr(handle);
	if (p)
	{
		printf("%02X:%02X:%02X:%02X:%02X:%02X\n",
		p->ether_addr_octet[0],
		p->ether_addr_octet[1],
		p->ether_addr_octet[2],
		p->ether_addr_octet[3],
		p->ether_addr_octet[4],
		p->ether_addr_octet[5]);
		free(p);
	}
	else
	{
		fprintf(stderr, "%s\n", libnet_geterror(handle));
	}
}

int main()
{
	char e[LIBNET_ERRBUF_SIZE] = {0};
	libnet_t *handle = NULL;

	handle = libnet_init(LIBNET_LINK, "em0", e);
	if (handle)
	{
		DoMyWork(handle);
		assert(handle != NULL);
		libnet_destroy(handle);
	}
	else
	{
		/*Report an error message*/
		char *msg;
		msg = libnet_geterror(handle);
		if (!msg)
		{
			msg = "You need to be root to access hardware";
		}
		fprintf(stderr, "%s():%d: %s\n", __func__, __LINE__, msg);
	}
	return(0);
}

