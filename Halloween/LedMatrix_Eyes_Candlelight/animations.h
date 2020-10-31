
#define ANIMATION_LENGTH(animation) sizeof(animation)/8

struct animation
{
  const uint64_t *frames;
  const unsigned int length; 
  uint16_t speed;
};

const uint64_t krgui64BLINK[] = {
  0x3c7effe7e7ff7e3c,
  0x007effe7e7ff7e00,
  0x0000ffe7e7ff0000,
  0x000000e7e7000000,
  0x0000000000000000,
  0x000000e7e7000000,
  0x0000ffe7e7ff0000,
  0x007effe7e7ff7e00,
  0x3c7effe7e7ff7e3c
};

const uint64_t ui64DOWN_UP[] = {
  0x3c7effe7e7ff7e3c,
  0x3c7ee7e7ffff7e3c,
  0x3c66e7ffffff7e3c,
  0x3c7ee7e7ffff7e3c,
  0x3c7effe7e7ff7e3c,
  0x3c7effffe7e77e3c,
  0x3c7effffffe7663c,
  0x3c7effffe7e77e3c,
  0x3c7effe7e7ff7e3c,
};

const uint64_t ui64UP_DOWN[] = {
  0x3c7effe7e7ff7e3c,
  0x3c7effffe7e77e3c,
  0x3c7effffffe7663c,
  0x3c7effffe7e77e3c,
  0x3c7effe7e7ff7e3c,
  0x3c7ee7e7ffff7e3c,
  0x3c66e7ffffff7e3c,
  0x3c7ee7e7ffff7e3c,
  0x3c7effe7e7ff7e3c
};

const uint64_t ui64RIGHT_OUT_LEFT_IN[] = { 
  0x3c7effe7e7ff7e3c,
  0x3c7effcfcfff7e3c,
  0x3c7eff9f9fff7e3c,
  0x3c7eff3f3fff7e3c,
  0x3c7eff7e7eff7e3c,
  0x3c7efffcfcff7e3c,
  0x3c7efff9f9ff7e3c,
  0x3c7efff3f3ff7e3c,
  0x3c7effe7e7ff7e3c
};

const uint64_t ui64ONE_ROUND[] = {
  0x3c7effe7e7ff7e3c,
  0x3c7effcfcfff7e3c,
  0x3c7eff9f9fff7e3c,
  0x3c7e9f9fffff7e3c,
  0x3c1e9fffffff7e3c,
  0x3c4ecfffffff7e3c,
  0x3c66e7ffffff7e3c,
  0x3c72f3ffffff7e3c,
  0x3c78f9ffffff7e3c,
  0x3c7ef9f9ffff7e3c,
  0x3c7efff9f9ff7e3c,
  0x3c7efffff9f97e3c,
  0x3c7efffffff9783c,
  0x3c7efffffff3723c,
  0x3c7effffffe7663c,
  0x3c7effffffcf4e3c,
  0x3c7effffff9f1e3c,
  0x3c7effff9f9f7e3c,
  0x3c7eff9f9fff7e3c,
  0x3c7effcfcfff7e3c,
  0x3c7effe7e7ff7e3c
};

const uint64_t ui64LOOK_RDOWN[] = {
  0x3c7effe7e7ff7e3c,
  0x3c7effcfcfff7e3c,
  0x3c7ecfcfffff7e3c
};

const uint64_t ui64LOOK_RDOWN_BACK[] = {
  0x3c7ecfcfffff7e3c,
  0x3c7effcfcfff7e3c,
  0x3c7effe7e7ff7e3c
};

const uint64_t ui64LOOK_LDOWN[] = {
  0x3c7effe7e7ff7e3c,
  0x3c7efff3f3ff7e3c,
  0x3c7ef9f9ffff7e3c
};

const uint64_t ui64LOOK_LDOWN_BACK[] = {
  0x3c7ef9f9ffff7e3c,
  0x3c7efff3f3ff7e3c,
  0x3c7effe7e7ff7e3c
};

const uint64_t ui64LOOK_RUP[] = {
  0x3c7effe7e7ff7e3c,
  0x3c7effffe7e77e3c,
  0x3c7effffffcf4e3c
};

const uint64_t ui64LOOK_RUP_BACK[] = {
  0x3c7effffffcf4e3c,
  0x3c7effffe7e77e3c,
  0x3c7effe7e7ff7e3c
};

const uint64_t ui64LOOK_LUP[] = {
  0x3c7effe7e7ff7e3c,
  0x3c7effffe7e77e3c,
  0x3c7efffffff3723c
};

const uint64_t ui64LOOK_LUP_BACK[] = {
  0x3c7efffffff3723c,
  0x3c7effffe7e77e3c,
  0x3c7effe7e7ff7e3c
};

const uint64_t ui64CLOSE_EYE[] = {
  0x3c7effe7e7ff7e3c,
  0x3c7effe7e7ff7e00,
  0x3c7effe7e7ff0000,
  0x007effe7e7000000,
  0x0000ffe700000000,
  0x0000000000000000
};

const uint64_t ui64RIGHT_EYE_EVILE[] = {
  0x1c3e27677ff8c000,
  0x1c3e33737ff8c000,
  0x1c3e27677ff8c000,
  0x1c3e0f4f7ff8c000,
  0x1c3e27677ff8c000
};

const uint64_t ui64LEFT_EYE_EVILE[] = {
  0x387ccccefe1f0300,
  0x387c9c9efe1f0300,
  0x387ccccefe1f0300,
  0x387ce4e6fe1f0300,
  0x387ccccefe1f0300
};
