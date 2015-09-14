Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/CommandLineArguments


---


# Command line arguments #

This page describes command line arguments that can be passed to phpdesktop executable.

## Chrome switches ##

You can pass many of Chrome command line switches to phpdesktop-chrome.exe, see:<br>
<a href='http://peter.sh/experiments/chromium-command-line-switches/'>http://peter.sh/experiments/chromium-command-line-switches/</a>

See also "command_line_switches" option on the ChromeSettings wiki page.<br>
<br>
<h2>--cgi-environment</h2>

Wth this argument you can pass custom environment variables to PHP. These variables will be appended to the <code>$_ENV</code> array. See example:<br>
<pre><code>phpdesktop-chrome.exe --cgi-environment="SOME=1,ABC=2"<br>
</code></pre>

Now if you do <code>print_r($_ENV)</code> in a php script you should see:<br>
<pre><code>Array<br>
(<br>
    [SERVER_NAME] =&gt; 127.0.0.1<br>
    ..<br>
    [SOME] =&gt; 1<br>
    [ABC] =&gt; 2<br>
)<br>
</code></pre>

You can overwrite arbitrary environment variables like <code>SERVER_NAME</code> or any other.<br>
<br>
What is this feature needed for? For example, you can launch an another phpdesktop app window from an existing app, and pass custom parameters so that you can differentiate both app launches. You can mix it with passing of Chrome switches to achieve various functionality.