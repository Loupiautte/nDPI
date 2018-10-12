folders="tcp udp"
for folder in $folders; do
	cd $folder
	name_upper=$(echo $folder | awk '{print toupper($0)}')
	name_define="#define NB_${name_upper}_PROTOCOL"
	nb_protocol=$(cat ${folder}_protocols.h | grep "register_" -c)
	protocols=()

	#Récupération de la priorité et du nom du protocole
	#Changement de l'extension (.cc => .c)
	for f in lpi_*.cc; do
		p=$(echo $f | cut -f 1 -d '.')
		pattern="static lpi_module_t $p"
		name=${p:4}
		priority=$(grep -Pazoe "static lpi_module_t [a-zA-Z0-9_]* = {\s*.*\s*.*\s*.*\s*\K[0-9]*" $f)
		protocol=${priority}.${name}
		protocols=("${protocols[@]}" $protocol)
		mv "$f" "${f%.cc}.c"
	done

	#Modification des fichiers principaux pour TCP ou UDP
	cd ..
	name_function="register_${folder}_protocols(LPIModuleArray \*mod_array)"
	sed -i ':again;$!N;$!b again; s/'"$name_function"' {[^}]*}/'"$name_function"' {'"$register_protocol"'return 0;}/g' proto_manager.c
	sed -i "s/$name_define [0-9]*/$name_define $nb_protocol/g" proto_manager.h
done