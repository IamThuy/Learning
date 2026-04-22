using System;
using System.Net;
using System.Net.Sockets;
using System.Reflection;
using Microsoft.Win32;
using System.Drawing;


internal class Program
{
    static async Task Main(string[] args)
    {
        string palavra = "Papel";
        int erros = 0;
        while (true)
        {
            string cabeça = erros >= 1 ? @"\O/" : " ";
            string corpo = erros >= 2 ? "()" : " ";
            string pernas = erros == 3 ? "_||_" : " ";

            Console.WriteLine("   " + cabeça);
            Console.WriteLine("   " + corpo);
            Console.WriteLine("  " + pernas);

            Console.WriteLine("Digite alguma palavra: ");
            if (erros == 3)
            {
                Console.WriteLine("Você perdeu!");
                break;
            }
            string tentativa = Console.ReadLine()!;
            if (tentativa == palavra)
            {
                Console.WriteLine("Você acertou!");
            }
            else
            {
                erros += 1;
            }

        }
    }
}

