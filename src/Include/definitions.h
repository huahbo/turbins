#ifndef DEFINITIONS_H
 #define DEFINITIONS_H

/* Let PETSc decompose the physical domain among the processors */
#undef AUTOMATIC_DOMAIN_PARTITIONING
/* Manually partition the domain. Note that the user is resposnible for correct values and the parallel layout among processors */
/* The parallel layout should be defined in both Grid.c and Output.c (_create functions) */
/* See Communication.c for further details */
#define  MANUAL_DOMAIN_PARTITIONING

#ifndef PI
#define PI 3.1415926536589793
#endif
#ifndef GVG_PI
#define GVG_PI 3.1415926536589793
#endif

#define NO  0
#define no  0
#define YES 1
#define yes 1

#define DRIVEN_CAVITY 0
#define LOCK_EXCHANGE 1

#define CONSTANT_VISCOSITY 0
#define VARIABLE_VISCOSITY 1

#define OPENDX   0
#define TECPLOT  1
#define PARAVIEW 2

/* For outflow velocity */
#define CONVECTIVE_CONSTANT_VELOCITY 0
#define CONVECTIVE_MAXIMUM_VELOCITY 1


/* Memory allocation */
#define GVG_CHAR      0
#define GVG_SHORT_INT 1
#define GVG_INT       2
#define GVG_LONG_INT  3
#define GVG_FLOAT     4
#define GVG_DOUBLE    5

#define SALINITY    1
#define PARTICLE    2
#define TEMPERATURE 3

#define maximum(a,b) ((a)<(b)?(b):(a))
#define minimum(a,b) ((a)>(b)?(b):(a))

#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)>(b)?(b):(a))

#ifndef sign 
	#define sign(a) ( ((a) > 0.0) ? 1 : ( (a) < 0.0 ? -1 : 0) )
#endif 

/* Stencil of finite difference scheme */
#define STENCIL 7

/* Parallel communicators */
#define PCW PETSC_COMM_WORLD
#define PCS PETSC_COMM_SELF

/* Root processor id */
#define MASTER 0

/* output data type */
#define BINARY 1
#define ASCII  2
#define HDF5   3

/* Global communication */
#define REDUCE_TO_MASTER 0 
#define REDUCE_TO_ALL 1 

/* states of the nodes */
#define NORTH 0
#define SOUTH 1
#define EAST  2 
#define WEST  3 
#define BACK  4
#define FRONT 5
#define OTHER 6

/* Error analysis */
#define NORM1    1
#define NORM2    2
#define NORM_INF 3

/* Grid status */
#define OUTSIDE  1
#define SOLID    2
#define FLUID    3
#define IMMERSED 5
#define BOUNDARY 7
#define BUFFER_SOLID 11

/* Maximum number of neighboring fluid nodes could be searched for find the right fluid nodes for each immersed node */
#define IBM_MAX 8 

/* Boundary conditions */
#define DIRICHLET 0 
#define NEUMANN   1
#define ROBBIN    2

#define MAX_PATH_LEN 4096
#define GVG_INF    10000000

/********************************************************************************************/
/* Use this function instead of PETScErrAct(ierr) in PETSc to stop the code                        */
/* This will make sure to stop the code exactly at the point where PETSc error occurs       */
/********************************************************************************************/
#define PETScErrAct(n) {\
if (n) {                                                                    \
         PetscError(__LINE__,__func__,__FILE__,__SDIR__,n,0," ");           \
         PetscPrintf(PCW, "Something wrong! Terminating the program...\n"); \
         PetscFinalize();                                                   \
         exit(1);                                                           \
     }                                                                      \
}
/********************************************************************************************/

#define SOLVE_INSIDE_SOLID
#define SOLVE_CONC

#undef MEMORY_PROFILING

extern double mem1;
extern double mem2;
extern int grid_mem;
extern int u_mem;
extern int v_mem;
extern int w_mem;
extern int c_mem;
extern int p_mem;
extern int u_solver_mem;
extern int v_solver_mem;
extern int w_solver_mem;
extern int c_solver_mem;
extern int p_solver_mem;

#define SINGLE_FILE_OUTPUT 1
#define PARTITIONED_FILES_OUTPUT 2

#undef TVD_RK3
#define TVD_RK2

/* Threshold beyond which the interpolation coefficients are inserted into the linear system matrices */
#define LSYS_DROP_TOLERANCE 1e-8

#define PETSC_VEC 1
#define PETSC_MAT 2

#define NOT_FOUND -1

#endif



