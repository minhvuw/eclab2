# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY nfl_score.c .
# Compile the C program
RUN gcc -o nfl_score nfl_score.c
# Set the command to run when the container starts
CMD ["./nfl_score"]