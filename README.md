# F28069_base

Repositório de desenvolvimento do código base para o controle de um conversor Boost

## Pré Requisitos

* Hardware necessários para desenvolvimento.

```
- LaunchPad F28069
```

* Softwares necessários para desenvolvimento deste kit.

```
OBS: É recomendado instalar todos softwares no repositório padrão C:\ti

- Code Composer Studio v9.0

```


## Instruções

### Estrutura do Repositório

Os componentes deste repositório podem ser exemplificados por:

```
TEAM -> PROJECT -> REPOSITORIES -> BRANCHES -> COMMITS
```


### Criando o Projeto no CCS e Utilizando o Repositório

* Crie uma Workspace pro Code Composer Studio

```
OBS: É recomendado criar a workspace no repositório padrão "C:\ti", i.e., "C:\ti\workspace_enel21_dsp"
```

* Crie e conecte um repositório local com o repositório remoto dentro da Workspace criada:

```
Criando repositório local:
- Com o CCS aberto, clique em View -> Other... -> Git Repositories
- Na aba "Git Repositories" clique em "Create a new local Git repository"
- Escolha o diretório da sua workspace para criar, i.e., "C:\ti\workspace_enel21_dsp"
- Clique em Finish

Conectando com o repositório remoto:
- Na aba "Git Repositories" agora irá ter um repositório git conforme foi criado
- Nesse repositório clique com o botão direito em "Remotes" e após selecione "Create Remote..."
- Na janela que irá se abrir configure:
   - Remote name: origin
   - Selecione: Configure fetch
- Aperte OK
- Na próxima janela clique em "Change...", preencha com os dados do repositório do bitbucket e clique em "Finish"
- Clique em Save and Fetch
- Conclua

Criando branch local a partir do repositório remoto:
- Na aba "Git Repositories", no repositório git criado, clique com o botão direito em "Branches" e após "Switch To -> New Branch..."
- Na janela que irá se abrir clique em "Select", escolha "origin/master" e clique em "Finish"

Importando o projeto:
- No CCS clique em Project -> Import CCS Project...
- Selecione o repositório do workspace
- Importe os projetos que foram criados a partir do reposítório remoto
```

### Configurando o Projeto no CCS

* Desabilite uma função nas propriedades do projeto:

```
- Vá em: Project Proprerties / Debug / Auto Run and Launch Options
- Desmarque as opções
- Marque apenas a opção "Connect to the target on debugger startup"
```

### Criando novos Branches no Repositório

O branch "master" sempre será o principal, atualizado sempre pelo admin do repositório.

Novas funções devem sempre ser desenvolvidas em branches auxiliares.

* Criando uma nova branch:

```
- Clique com o botão direito em cima do projeto -> Team -> Switch To -> New Branch...
- Escolha a fonte do novo branch
-- Por exemplo, se for criar uma branch para adicionar funcionabilidade ao inversor, escolha a branch fonte do inversor
- Adicione um nome sugestivo a nova branch
-- Por exemplo, se for adicionar uma função de proteção no inversor de o nome de: Ftr_Inversor_Protecao_Corrente
- Conclua
```

* Dando commit:

```
- Clique com o botão direito em cima do projeto -> Team -> Commit...
-- Uma nova aba, Git Staging, irá abrir
- Escolha as modificações em "Unstaged Changes" e arrasta para "Staged Changes"
- Escolha uma mensagem de commit
-- A primeira linha da mensagem é o título, as próximas são os comentários
- Clique em "Commit and Push..."
- Conclua
```

* Fazendo Merge de Branches:

```
- Quando a nova função tiver sido testada e completada é hora de fundir (merge) a branch fonte. Para isso:
-- É necessário ter dado commit na branch atual
-- Após é necessário trocar para a branch fonte
-- Após é necessário dar merge entre as branches
- Tendo dado commit na branch da nova função e estando na branch fonte
-- Clique com o botão direito em cima do projeto -> Team -> Merge...
-- Na aba "Local" selecione a branch da nova função à qual a branch fonte deve se fundir
-- Em "Fast forward options" selecione a opção "If a fast-forward, create a merge-commit"
- Conclua
```

## Autor

* **Luiz Carlos Gili**
