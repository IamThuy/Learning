using System;

namespace MyApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Humano p;
            p = new Jorge();
            p.Falar();
            p.Gritar();

            p = new Lucas();
            p.Falar();
            p.Gritar();
        }
    }
}