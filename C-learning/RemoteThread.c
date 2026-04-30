HANDLE hThread = CreateRemoteThreadEx(
    hProcess, 
    // ↑ HANDLE do processo alvo
    // Esse handle vem do OpenProcess.
    // Ele representa "qual processo" vai receber a nova thread.
    // Tudo que acontecer aqui dentro vai acontecer NO CONTEXTO desse processo.

    NULL, 
    // ↑ LPSECURITY_ATTRIBUTES
    // Define atributos de segurança da thread (quem pode acessar, herança de handle, etc).
    // NULL = usa padrão do sistema.
    // Na prática: 99% dos casos você ignora isso.

    0, 
    // ↑ SIZE_T dwStackSize
    // Tamanho da stack da thread (memória usada para chamadas de função locais).
    // 0 = o Windows usa o tamanho padrão (geralmente ~1MB).
    // Só muda isso se você tiver um motivo MUITO específico (quase nunca).

    (LPTHREAD_START_ROUTINE)loadLibrary, 
    // ↑ lpStartAddress (ENDEREÇO DA FUNÇÃO)
    // Aqui você passa um PONTEIRO para a função que será executada.
    // Nesse caso: endereço de LoadLibraryA dentro da kernel32.dll.
    //
    // IMPORTANTE:
    // Isso NÃO é o nome da função, é o ENDEREÇO REAL dela na memória.
    //
    // Quando a thread começar, o CPU vai fazer:
    // RIP/EIP = loadLibrary
    //
    // Ou seja, ela começa executando exatamente essa função.

    remoteMemory, 
    // ↑ lpParameter (PARÂMETRO DA FUNÇÃO)
    // Esse valor é passado como argumento para a função acima.
    //
    // LoadLibraryA espera: const char* (caminho da DLL)
    //
    // Então isso vira:
    // LoadLibraryA(remoteMemory);
    //
    // E remoteMemory aponta para:
    // "C:\\caminho\\minha.dll"
    //
    // MUITO IMPORTANTE:
    // Esse ponteiro precisa existir NO PROCESSO ALVO.
    // Por isso usamos VirtualAllocEx + WriteProcessMemory antes.

    0, 
    // ↑ dwCreationFlags
    // Define como a thread será criada.
    //
    // 0 = executa imediatamente
    //
    // Alternativa importante:
    // CREATE_SUSPENDED → cria a thread PAUSADA
    // (você pode manipular antes de dar ResumeThread)

    NULL, 
    // ↑ lpAttributeList (LPPROC_THREAD_ATTRIBUTE_LIST)
    // Estrutura avançada para configurar a thread.
    //
    // Permite coisas como:
    // - spoof de processo pai
    // - definir afinidade de CPU
    // - bypass de proteções
    //
    // Isso é nível avançado (anti-cheat, evasão, etc)
    //
    // NULL = não usar nada disso

    NULL 
    // ↑ lpThreadId
    // Ponteiro para receber o ID da thread criada.
    //
    // Exemplo:
    // DWORD tid;
    // CreateRemoteThreadEx(..., &tid);
    //
    // Aqui você ignorou → NULL
);
