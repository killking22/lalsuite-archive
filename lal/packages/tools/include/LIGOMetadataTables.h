/*----------------------------------------------------------------------- 
 * 
 * File Name: LIGOMetadataTables.h
 *
 * Author: Brown, D. A.
 * 
 * Revision: $Id$
 * 
 *-----------------------------------------------------------------------
 */

#if 0
<lalVerbatim file="LIGOMetadataTablesHV">
Author: Brown, D. A.
$Id$
</lalVerbatim> 
<lalLaTeX>
\section{Header \texttt{LIGOMetadataTables.h}}
\label{s:LIGOMetadataTables.h}

Provides data type definitions for the LIGO metadata database tables. Only
columns that are available for the user defined values are available in the
structures. For example the \texttt{process\_id} column in the
\texttt{sngl\_inspiral} table is not in the corresponding LAL structure as it
is generated by the database on insertion of events, not by the user.

\subsection*{Synopsis}
\begin{verbatim}
#include <lal/FindChirpEngine.h>
\end{verbatim}

</lalLaTeX>
#endif

#ifndef _LIGOMETADATATABLES_H
#define _LIGOMETADATATABLES_H

#ifdef  __cplusplus
extern "C" {
#pragma }
#endif

NRCSID( LIGOMETADATATABLESH, "$Id$" );

/* defines for lengths of database table char arrays       */
/* one longer than as defined in the SQL tables to allow   */
/* strage of the terminating null need for the C %s format */
#define LIGOMETA_PROGRAM_MAX 17
#define LIGOMETA_VERSION_MAX 65
#define LIGOMETA_CVS_REPOSITORY_MAX 257
#define LIGOMETA_COMMENT_MAX 241
#define LIGOMETA_NODE_MAX 65
#define LIGOMETA_USERNAME_MAX 65
#define LIGOMETA_DOMAIN_MAX 64
#define LIGOMETA_IFOS_MAX 13
#define LIGOMETA_PARAM_MAX 33
#define LIGOMETA_TYPE_MAX 17
#define LIGOMETA_VALUE_MAX 1025
#define LIGOMETA_NAME_MAX 65
#define LIGOMETA_STRING_MAX 257
#define LIGOMETA_IFO_MAX 3
#define LIGOMETA_SEARCH_MAX 25
#define LIGOMETA_CHANNEL_MAX 65
#define LIGOMETA_FRAMESETG_MAX 49
#define LIGOMETA_SEGMENTG_MAX 49
#define LIGOMETA_SUMMVALUE_NAME_MAX 129
#define LIGOMETA_SUMMVALUE_COMM_MAX 81
#define LIGOMETA_UNIQUE_MAX 65
#define LIGOMETA_DBUNIQUE_MAX 13
#define LIGOMETA_TRANSDATA_EVENT_TABLE_MAX 19
#define LIGOMETA_TRANSDATA_NAME_MAX 33
#define LIGOMETA_TRANSDATA_UNITS_MAX 17
#define LIGOMETA_TRANSDATA_DATA_MAX 17

#if 0
<lalLaTeX>
\subsection*{Types}
\idx[Type]{MetadataTable}
\idx[Type]{ProcessTable}
\idx[Type]{ProcessParamsTable}
\idx[Type]{SearchSummaryTable}
\idx[Type]{SearchSummvarsTable}
\idx[Type]{SnglBurstTable}
\idx[Type]{SnglInspiralTable}
\idx[Type]{SummValueTable}

\subsubsection*{Type \texttt{MetadataTableType}}
</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef enum
{
  no_table,
  process_table,
  process_params_table,
  search_summary_table,
  search_summvars_table,
  sngl_burst_table,
  sngl_inspiral_table,
  sngl_transdata_table,
  summ_value_table
}
MetadataTableType;
/*</lalVerbatim> */
#if 0
<lalLaTeX>
The \texttt{MetadataTableType} contains an enum type for each of the possible
database tables that are provided.
\subsubsection*{Type \texttt{ProcessTable}}
</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef struct
tagProcessTable
{
  struct tagProcessTable *next;
  CHAR          program[LIGOMETA_PROGRAM_MAX];
  CHAR          version[LIGOMETA_VERSION_MAX];
  CHAR          cvs_repository[LIGOMETA_CVS_REPOSITORY_MAX];
  LIGOTimeGPS   cvs_entry_time;
  CHAR          comment[LIGOMETA_COMMENT_MAX];
  INT4          is_online;
  CHAR          node[LIGOMETA_NODE_MAX];
  CHAR          username[LIGOMETA_USERNAME_MAX];
  LIGOTimeGPS   start_time;
  LIGOTimeGPS   end_time;
  INT4          jobid;
  CHAR          domain[LIGOMETA_DOMAIN_MAX];
  INT4          unix_procid;
  CHAR          ifos[LIGOMETA_IFOS_MAX];
}
ProcessTable;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

Document table.

\subsubsection*{Type \texttt{ProcessParamsTable}}

</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef struct
tagProcessParamsTable
{
  struct tagProcessParamsTable *next;
  CHAR          program[LIGOMETA_PROGRAM_MAX];
  CHAR          param[LIGOMETA_PARAM_MAX];
  CHAR          type[LIGOMETA_TYPE_MAX];
  CHAR          value[LIGOMETA_VALUE_MAX];
}
ProcessParamsTable;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

Document table.

\subsubsection*{Type \texttt{SearchSummaryTable}}

</lalLaTeX>
#endif
/* <lalVerbatim> */

/* shared object is lalapps, lalwrapper_cvs_tag is lalapps cvs tag */
/* lal_cvs tag is populated automatically                          */
typedef struct
tagSearchSummaryTable
{
  struct tagSearchSummaryTable *next;
  CHAR          comment[LIGOMETA_COMMENT_MAX];
  LIGOTimeGPS   in_start_time;
  LIGOTimeGPS   in_end_time;
  LIGOTimeGPS   out_start_time;
  LIGOTimeGPS   out_end_time;
  INT4          nevents;
  INT4          nnodes;
}
SearchSummaryTable;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

Document table.

\subsubsection*{Type \texttt{SearchSummvarsTable}}

</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef struct
tagSearchSummvarsTable
{
  struct tagSearchSummvarsTable *next;
  CHAR          name[LIGOMETA_NAME_MAX];
  CHAR          string[LIGOMETA_STRING_MAX];
  REAL8         value;
}
SearchSummvarsTable;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

Document table.

\subsubsection*{Type \texttt{EventIDColumn}}

</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef struct
tagEventIDColumn
{
  struct tagEventIDColumn *next;
  UINT4  id;
  CHAR   textId[LIGOMETA_UNIQUE_MAX];
  UCHAR  dbUniqueId[LIGOMETA_DBUNIQUE_MAX];
  struct tagSnglBurstTable      *snglBurstTable;
  struct tagSnglInspiralTable   *snglInspiralTable;
  struct tagSummValueTable      *summValueTable;
  struct tagSnglTransData       *snglTransdataTable;
}
EventIDColumn;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

The \texttt{EventIDColumn} structure is used to link different tables that
refer to the same event. The database column \texttt{event\_id} is a ID
generated by the database that is generally unique within a given event table
(e.g. \texttt{sngl\_inspiral} or \texttt{sngl\_burst}), but may be shared 
across tables. For example, an entry in the \texttt{sngl\_burst} may have
several entries in the \texttt{sngl\_transdata} table with the same event ID
or a \texttt{sngl\_inspiral} many have a corresponding entry in the
\texttt{sngl\_burst} with the same event ID, e.g. for an inspiral-ringdown 
search.

When the LAL XML output routines are called, the generate XML that the 
database can interpret to set the \texttt{event\_id} columns correctly
in the tables.

If the user does not wish to make use of the event ID at the level of the 
search, for eaxmple if the user is generating a list of inspiral events 
and does not want to link these to any other tables, the \texttt{event\_id}
pointer in the \texttt{SnglInpiralTable} may be set to NULL. In this case
the XML output routines will generate the correct XML to tell the database
to generate a unique event ID for each inspiral event, but these should not
be shared across tables.

\subsubsection*{Type \texttt{SnglBurstTable}}

</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef struct
tagSnglBurstTable
{
  struct tagSnglBurstTable *next;
  CHAR          ifo[LIGOMETA_IFO_MAX];
  CHAR          search[LIGOMETA_SEARCH_MAX];
  CHAR          channel[LIGOMETA_CHANNEL_MAX];
  LIGOTimeGPS   start_time;
  REAL4         duration;
  REAL4         central_freq;
  REAL4         bandwidth;
  REAL4         amplitude;
  REAL4         snr;
  REAL4         confidence;
  EventIDColumn *event_id;
}
SnglBurstTable;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

Document table.

\subsubsection*{Type \texttt{SnglInspiralTable}}

</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef struct
tagSnglInspiralTable
{
  struct tagSnglInspiralTable *next;
  CHAR          ifo[LIGOMETA_IFO_MAX];
  CHAR          search[LIGOMETA_SEARCH_MAX];
  CHAR          channel[LIGOMETA_CHANNEL_MAX];
  LIGOTimeGPS   end_time;
  LIGOTimeGPS   impulse_time;
  REAL8         template_duration;
  REAL8         event_duration;
  REAL4         amplitude;
  REAL4         eff_distance;
  REAL4         coa_phase;
  REAL4         mass1;
  REAL4         mass2;
  REAL4         mchirp;
  REAL4         eta;
  REAL4         tau0;
  REAL4         tau2;
  REAL4         tau3;
  REAL4         tau4;
  REAL4         tau5;
  REAL4         ttotal;
  REAL4         snr;
  REAL4         chisq;
  INT4          chisq_dof;
  REAL8         sigmasq;
  EventIDColumn *event_id;
}
SnglInspiralTable;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

Document table.

\subsubsection*{Type \texttt{SnglTransdataTable}}

</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef struct
tagSnglTransdataTable
{
  CHAR          event_table[LIGOMETA_TRANSDATA_EVENT_TABLE_MAX];
  CHAR          ifo[LIGOMETA_IFO_MAX];
  CHAR          name[LIGOMETA_TRANSDATA_NAME_MAX];
  INT4          dimensions;
  INT4          x_bins;
  REAL8         x_start;
  REAL8         x_end;
  CHAR          x_units[LIGOMETA_TRANSDATA_UNITS_MAX];
  INT4          y_bins;
  REAL8         y_start;
  REAL8         y_end;
  CHAR          y_units[LIGOMETA_TRANSDATA_UNITS_MAX];
  CHAR          data_type[LIGOMETA_TRANSDATA_DATA_MAX];
  CHAR          data_units[LIGOMETA_TRANSDATA_DATA_MAX];
  UCHAR         *trans_data; /* must be big Endian */
  INT4          transdata_length;
  EventIDColumn *event_id;
}
SnglTransdataTable;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

Document table.

\subsubsection*{Type \texttt{SummValueTable}}

</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef struct
tagSummValueTable
{
  struct tagSummValueTable *next;
  CHAR          program[LIGOMETA_PROGRAM_MAX];
  CHAR          frameset_group[LIGOMETA_FRAMESETG_MAX];
  CHAR          segment_group[LIGOMETA_SEGMENTG_MAX];
  INT4          version;
  LIGOTimeGPS   start_time;
  LIGOTimeGPS   end_time;
  CHAR          ifo[LIGOMETA_IFO_MAX];
  CHAR          name[LIGOMETA_SUMMVALUE_NAME_MAX];
  REAL4         value;
  REAL4         error;
  INT4          intvalue;
  CHAR          comment[LIGOMETA_SUMMVALUE_COMM_MAX];
}
SummValueTable;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

Document table.

\subsubsection*{Type \texttt{MetadataTable}}

</lalLaTeX>
#endif
/* <lalVerbatim> */
typedef union
tagMetadataTable
{
  ProcessTable          *processTable;
  ProcessParamsTable    *processParamsTable;
  SearchSummaryTable    *searchSummaryTable;
  SearchSummvarsTable   *searchSummvarsTable;
  SnglBurstTable        *snglBurstTable;
  SnglInspiralTable     *snglInspiralTable;
  SnglTransdataTable    *snglTransdataTable;
  SummValueTable        *summValueTable;
}
MetadataTable;
/* </lalVerbatim> */
#if 0
<lalLaTeX>

Document table.

\vfill{\footnotesize\input{LIGOMetadataTablesHV}}
</lalLaTeX>
#endif

#ifdef  __cplusplus
#pragma {
}
#endif

#endif /* _LIGOMETADATATABLES_H */
