cd /etc/apt
mv sources.list sources.list_bak
wget ftp://172.16.2.4/Linux/sources.list
apt-get update 
apt-get -y install vim ssh gcc g++ cscope synaptic gecko-mediaplayer samba
cd /opt
wget ftp://172.16.2.4/Linux/firefox64/firefox-61.0.1.tar.bz2
tar -xvf firefox-61.0.1.tar.bz2
cd /usr/bin
mv firefox firefox_old
ln -s /opt/firefox/firefox /usr/bin/firefox
cd /opt
wget ftp://172.16.2.4/Linux/firefox64/gstreamer.deb
dpkg -i gstreamer.deb
cd /etc
mv ntp.conf ntp.conf.old
wget ftp://172.16.2.4/linux/ntp.conf
service ntp restart

