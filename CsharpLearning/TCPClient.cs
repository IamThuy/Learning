using System;
using System.Net;
using System.Net.Http.Json;
using System.Net.Sockets;
using System.Text;
namespace MyApp
{
    internal class Program
    {
        static async Task Main(string[] args)
        {
            TcpListener server = new TcpListener(IPAddress.Any, 8080);
            server.Start();

            Console.WriteLine("Server iniciado");

            while (true)
            {
                TcpClient client = server.AcceptTcpClient();
                NetworkStream stream = client.GetStream();


                // cria um array de bytes e guarda os bytes q chegaram na rede dentro desse array
                byte[] buffer = new byte[1024];
                int bytes = stream.Read(buffer, 0, buffer.Length);

                // pega os bytes válidos (de 0 até a quantidade de bytes que guardamos antes) transformamos em string e mostramos
                string msg = Encoding.UTF8.GetString(buffer, 0, bytes);
                Console.WriteLine(msg);

                Console.WriteLine("Escreva a resposta");
                string resposta = Console.ReadLine();

                // fazemos a mesma coisa q antes mas para pegar os bytes da resposta e mandar na rede
                byte[] resp = Encoding.UTF8.GetBytes(resposta);
                stream.Write(resp, 0, resp.Length);

                client.Close();
            }
        }
    }
}
