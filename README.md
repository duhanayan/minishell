<!DOCTYPE html>
<html>
<head>
	<title>Minishell</title>
</head>
<body>
	<h1>Minishell</h1>
	<p>Minishell, basit bir kabuk programıdır. Kullanıcının komut satırına girdiği komutları işleyen ve sonuçlarını gösteren bir programdır.</p>
	
	<h2>Kurulum</h2>
	<ol>
		<li>Minishell'in son sürümünü <a href="https://github.com/kullanici/minishell/releases/latest">buradan</a> indirin.</li>
		<li>İndirdiğiniz dosyayı açın ve terminalde <code>make</code> komutunu çalıştırın.</li>
		<li><code>./minishell</code> komutunu çalıştırarak Minishell'i başlatın.</li>
	</ol>

	<h2>Kullanım</h2>
	<p>Minishell, kullanıcı tarafından girilen komutları işler ve sonuçlarını gösterir. Komut satırına girdiğiniz komutları aşağıdaki şekilde kullanabilirsiniz:</p>

	<pre>$ komut [argümanlar]</pre>

	<p>Örnek olarak, <code>ls</code> komutu kullanarak mevcut dizindeki dosyaları listelemek için aşağıdaki komutu kullanabilirsiniz:</p>

	<pre>$ ls</pre>

	<p>Minishell, birçok farklı komutu destekler. Desteklenen tüm komutları görmek için <code>help</code> komutunu kullanabilirsiniz:</p>

	<pre>$ help</pre>

	<h2>Geliştirme</h2>
	<p>Minishell, C dili ile yazılmıştır. Geliştirme için aşağıdaki adımları izleyebilirsiniz:</p>
	<ol>
		<li>Depoyu klonlayın: <code>git clone https://github.com/kullanici/minishell.git</code></li>
		<li>Kodunuzu değiştirin.</li>
		<li>Değişikliklerinizi doğrulamak için testlerinizi çalıştırın: <code>make test</code></li>
		<li>Değişikliklerinizi yükleyin: <code>git push</code></li>
	</ol>

	<h2>Lisans</h2>
	<p>Bu program, MIT Lisansı ile lisanslanmıştır. Ayrıntılar için <code>LICENSE</code> dosyasını inceleyin.</p>
</body>
</html>
