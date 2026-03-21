using System;
using System.IO;

class Program
{
    static async Task Main()
    {
        using HttpClient client = new HttpClient();
        string caminho = "info.txt";

        string usuario = Environment.UserName;
        string maquina = Environment.MachineName;
        string os = Environment.OSVersion.ToString();
        string cpu = Environment.GetEnvironmentVariable("PROCESSOR_IDENTIFIER")!;
        string ip =  await client.GetStringAsync("https://api.ipify.org");

        string conteudo = $@"
                \\\ info ///
            {usuario}
            {maquina}
            {os}
            {cpu}
            {ip}
        ";

        File.WriteAllText(caminho, conteudo);

    }
}