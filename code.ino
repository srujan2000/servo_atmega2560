void init();
void init_timer();
void delay1();

void setup()
{
    init_port();
    init_timer();

    volatile short *OCR1_A = (short *)0x88;
    while (1)
    {
        for (int i = 1000; i < 5000; i++)
        {
            *OCR1_A = i;
            delay1();
        }

        for (int i = 5000; i >= 1000; i--)
        {
            *OCR1_A = i;
            delay1();
        }
    }
}

void init_port()
{
    volatile char *ddr = (char *)0x24;
    *ddr = 0x20;  //Set portb pin 5 as output i.e Pin11 on board
}

void init_timer()
{
    volatile char *TCCR1_A = (char *)0x80;
    volatile char *TCCR1_B = (char *)0x81;
    volatile short *TCNT_1 = (short *)0x84;
    volatile short *ICR_1 = (short *)0x86;

    *TCCR1_A = 0b10000010; // WGM0-0,WGM1-1,COMA1-1,COMA0-0
    *TCCR1_B = 0b00011010; // WGM2-1,WGM3-1, precaler-8
    *TCNT_1 = 0;
    *ICR_1 = 40000; // Sets frequency to 50Hz
}

void delay1()
{
    volatile long i;
    for (i = 0; i < 500; i++)
        ;
}

void loop()
{
}
