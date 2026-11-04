# É necessário primeiramente instalar os headers em sua Raspberry;
# Após a instalação deverá existir um diretório ./build/...; 
sudo apt update
sudo apt install raspberrypi-kernel-headers
sudo apt upgrade

# Copie ou carregue os arquivos dos projetos em um diretório. Exemplo: ./drivers/
# Dentro de cada projeto deverá existir o arquivo .c e o Makefile;
# Exemplo: ./driver/first_driver.c 
#          ./driver/Makefile
# Para compilar execute a chamada do programa make all; 

make all
# Após a compilação será gerado o arquivo .ko. Exemplo: first_driver.ko 
# Este arquivo .ko é o device driver (módulo) compilado. Podemos agora carregar no kernel
# via insmod;

sudo insmod first_driver.ko      #Carrega o driver no kernel;

#Após o carremento do driver no Kernel, as mensagens de logs podem ser verificadas via
# programa dmesg; 

dmesg | tail -n 20             #Apresenta logs do Kernel;

# Remove o driver do kernel;
sudo rmmod first_driver 
















