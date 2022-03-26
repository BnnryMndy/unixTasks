#owner username
owner=user

#getting semaphores, queues and shared memories 
semaphores_msqids=$(ipcs -s | grep "$owner *6**" | awk '{print $2}')
queue_msqids=$(ipcs -q | grep "$owner *6**" | awk '{print $2}')
shared_memore_msqids=$(ipcs -m | grep "$owner *6**" | awk '{print $2}')

#delete semaphores
isDeleting=0
for msqid in $semaphores_msqids
do
    ipcrm -s $msqid
    isDeleting=1
    echo "Semaphores" $msqid "deleted"
done 

if [ $isDeleting = 0 ]
then
     echo "Semaphores not found"  
fi

# delete queues 
isDeleting=0
for msqid in $queue_msqids
do
    ipcrm -q $msqid
    isDeleting=1
    echo "Queue" $msqid "deleted"
done 

if [ $isDeleting = 0 ]
then
     echo "Queues not found"  
fi

# #delete shared memories
isDeleting=0
for msqid in $shared_memore_msqids
do
    ipcrm -m $msqid
    isDeleting=1
    echo "Shared memory" $msqid "deleted"
done 

if [ $isDeleting = 0 ]
then
     echo "Shared memories not found"  
fi