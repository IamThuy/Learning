using System;

abstract class Humano
{
    public abstract void Gritar();

    public virtual void Falar()
    {
        Console.WriteLine("Barulho gen");
    }

    public Humano()
    {
        Console.WriteLine("Somos humanos");
    }
}