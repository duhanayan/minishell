# Minishell

Minishell, basit bir kabuk programıdır. Kullanıcının komut satırına girdiği komutları işleyen ve sonuçlarını gösteren bir programdır.

## Kurulum

1. Minishell'in son sürümünü [buradan](https://github.com/kullanici/minishell/releases/latest) indirin.
2. İndirdiğiniz dosyayı açın ve terminalde `make` komutunu çalıştırın.
3. `./minishell` komutunu çalıştırarak Minishell'i başlatın.

## Kullanım

Minishell, kullanıcı tarafından girilen komutları işler ve sonuçlarını gösterir. Komut satırına girdiğiniz komutları aşağıdaki şekilde kullanabilirsiniz:

$ komut [argümanlar]

Örnek olarak, `ls` komutu kullanarak mevcut dizindeki dosyaları listelemek için aşağıdaki komutu kullanabilirsiniz:

$ ls


Minishell, birçok farklı komutu destekler. Desteklenen tüm komutları görmek için `help` komutunu kullanabilirsiniz:

$ help


## Geliştirme

Minishell, C dili ile yazılmıştır. Geliştirme için aşağıdaki adımları izleyebilirsiniz:

1. Depoyu klonlayın: `git clone https://github.com/kullanici/minishell.git`
2. Kodunuzu değiştirin.
3. Değişikliklerinizi doğrulamak için testlerinizi çalıştırın: `make test`
4. Değişikliklerinizi yükleyin: `git push`

## Lisans

Bu program, MIT Lisansı ile lisanslanmıştır. Ayrıntılar için `LICENSE` dosyasını inceleyin.
