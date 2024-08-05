# PortHopper

A port forwarding tool written in C language

# Use
- Port forwarding, using -t (tran) mode to forward the desired internal network service to the machine
- Local forwarding,using -l (listen) mode to enable two local TCP listening services 
- Service forwarding, using -s(slave) mode to enable the specified desired port traffic to be forwarded to the machine that has enabled the listen service


# Example

```sh
python3 -m http.server
./PortHopper -t 8081 127.0.0.1 8000
# web service has enabled forwarding
```

```sh
# tmp1 10.16.1.2
./PortHopper -l 8081 8082

# web1
./PortHopper -s 10.16.1.2 8081 127.0.0.1 8000
# web service has enabled forwarding
```

# Build
```
# base
gcc ./PortHopper.c -o PortHopper
# Complete compilation
gcc -DANONYMOUS=1 -DCOMMAND_MODE ./PortHopper.c -o PortHopper
# Platform: windows
# set PLATFORM=windows then build
```

