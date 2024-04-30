FROM amazonlinux:2
# RUN yum install -y procps htop
WORKDIR /code
COPY ./create_memory_files.sh .

ENTRYPOINT [ "/code/create_memory_files.sh" ]
CMD [ "30" ]