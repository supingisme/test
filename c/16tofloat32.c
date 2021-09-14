uint32_t tofloat32(uint16_t f)
{
    uint16_t *i = (uint16_t *)&f;
    uint32_t sign = (*i >> 15)&0x1;
    uint32_t exponent = ((*i >> 11)&0xf)-0x7;
    uint32_t mantissa = (*i)&0x7ff;

    exponent += 0x7f;
    uint32_t ret = ((sign&0x1)<<31);
    ret |= (exponent & 0xff)<<23;
    ret |= (mantissa << 12) & 0x7fffff;

    return ret;
}

