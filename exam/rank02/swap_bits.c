unsigned char	swap_bits(unsigned char octet)
{
	unsigned char ret = 0;
	if (octet > 128)
	{
		octet = octet - 128;
		ret += 8;
	}
	if (octet > 64)
	{
		octet = octet - 64;
		ret += 4;
	}
	if (octet > 32)
	{
		octet = octet - 32;
		ret += 2;
	}
	if (octet > 16)
	{
		octet = octet - 16;
		ret += 1;
	}
	if (octet > 8)
	{
		octet = octet - 8;
		ret += 128;
	}
	if (octet > 4)
	{
		octet = octet - 4;
		ret += 64;
	}
	if (octet > 2)
	{
		octet = octet - 2;
		ret += 32;
	}
	if (octet > 1)
	{
		octet = octet - 1;
		ret += 16;
	}
	return (ret);
}