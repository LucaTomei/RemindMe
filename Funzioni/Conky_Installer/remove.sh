echo "Rimozione Files!\n"
echo "Conky-Manager, RealPath, conky*"
sudo apt purge conky-manager* && sudo apt purge conky* && sudo apt purge realpath* && sudo apt autoremove
echo "\n\nElimino file nel filesystem\n"
sudo rm -R ~/.conky
sudo rm ~/.config/autostart/conky.desktop
sudo rm ~/.config/conky-manager.json
