--
-- PostgreSQL database dump
--

-- Dumped from database version 14.12 (Homebrew)
-- Dumped by pg_dump version 16.3

-- Started on 2024-06-03 16:33:57 CEST

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 4 (class 2615 OID 2200)
-- Name: public; Type: SCHEMA; Schema: -; Owner: solomontaiwo
--

-- *not* creating schema, since initdb creates it


ALTER SCHEMA public OWNER TO solomontaiwo;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 214 (class 1259 OID 16412)
-- Name: active_storage_attachments; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.active_storage_attachments (
    id bigint NOT NULL,
    name character varying NOT NULL,
    record_type character varying NOT NULL,
    record_id bigint NOT NULL,
    blob_id bigint NOT NULL,
    created_at timestamp without time zone NOT NULL
);


ALTER TABLE public.active_storage_attachments OWNER TO postgres;

--
-- TOC entry 213 (class 1259 OID 16411)
-- Name: active_storage_attachments_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.active_storage_attachments_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.active_storage_attachments_id_seq OWNER TO postgres;

--
-- TOC entry 4055 (class 0 OID 0)
-- Dependencies: 213
-- Name: active_storage_attachments_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.active_storage_attachments_id_seq OWNED BY public.active_storage_attachments.id;


--
-- TOC entry 212 (class 1259 OID 16402)
-- Name: active_storage_blobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.active_storage_blobs (
    id bigint NOT NULL,
    key character varying NOT NULL,
    filename character varying NOT NULL,
    content_type character varying,
    metadata text,
    service_name character varying NOT NULL,
    byte_size bigint NOT NULL,
    checksum character varying NOT NULL,
    created_at timestamp without time zone NOT NULL
);


ALTER TABLE public.active_storage_blobs OWNER TO postgres;

--
-- TOC entry 211 (class 1259 OID 16401)
-- Name: active_storage_blobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.active_storage_blobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.active_storage_blobs_id_seq OWNER TO postgres;

--
-- TOC entry 4056 (class 0 OID 0)
-- Dependencies: 211
-- Name: active_storage_blobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.active_storage_blobs_id_seq OWNED BY public.active_storage_blobs.id;


--
-- TOC entry 216 (class 1259 OID 16428)
-- Name: active_storage_variant_records; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.active_storage_variant_records (
    id bigint NOT NULL,
    blob_id bigint NOT NULL,
    variation_digest character varying NOT NULL
);


ALTER TABLE public.active_storage_variant_records OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 16427)
-- Name: active_storage_variant_records_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.active_storage_variant_records_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.active_storage_variant_records_id_seq OWNER TO postgres;

--
-- TOC entry 4057 (class 0 OID 0)
-- Dependencies: 215
-- Name: active_storage_variant_records_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.active_storage_variant_records_id_seq OWNED BY public.active_storage_variant_records.id;


--
-- TOC entry 255 (class 1259 OID 16650)
-- Name: activity_students; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.activity_students (
    id bigint NOT NULL,
    extra_activity_id bigint,
    attend_scholastic_period_id bigint,
    "position" character varying,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.activity_students OWNER TO postgres;

--
-- TOC entry 254 (class 1259 OID 16649)
-- Name: activity_students_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.activity_students_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.activity_students_id_seq OWNER TO postgres;

--
-- TOC entry 4058 (class 0 OID 0)
-- Dependencies: 254
-- Name: activity_students_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.activity_students_id_seq OWNED BY public.activity_students.id;


--
-- TOC entry 210 (class 1259 OID 16394)
-- Name: ar_internal_metadata; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ar_internal_metadata (
    key character varying NOT NULL,
    value character varying,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.ar_internal_metadata OWNER TO postgres;

--
-- TOC entry 233 (class 1259 OID 16534)
-- Name: attachments; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.attachments (
    id bigint NOT NULL,
    category character varying,
    file_id bigint,
    filename character varying,
    url character varying,
    content_type character varying,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    attachable_type character varying,
    attachable_id bigint
);


ALTER TABLE public.attachments OWNER TO postgres;

--
-- TOC entry 232 (class 1259 OID 16533)
-- Name: attachments_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.attachments_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.attachments_id_seq OWNER TO postgres;

--
-- TOC entry 4059 (class 0 OID 0)
-- Dependencies: 232
-- Name: attachments_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.attachments_id_seq OWNED BY public.attachments.id;


--
-- TOC entry 275 (class 1259 OID 16844)
-- Name: attend_scholastic_period_evaluations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.attend_scholastic_period_evaluations (
    id bigint NOT NULL,
    attend_scholastic_period_id bigint NOT NULL,
    evaluation_id bigint NOT NULL,
    mark double precision
);


ALTER TABLE public.attend_scholastic_period_evaluations OWNER TO postgres;

--
-- TOC entry 274 (class 1259 OID 16843)
-- Name: attend_scholastic_period_evaluations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.attend_scholastic_period_evaluations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.attend_scholastic_period_evaluations_id_seq OWNER TO postgres;

--
-- TOC entry 4060 (class 0 OID 0)
-- Dependencies: 274
-- Name: attend_scholastic_period_evaluations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.attend_scholastic_period_evaluations_id_seq OWNED BY public.attend_scholastic_period_evaluations.id;


--
-- TOC entry 253 (class 1259 OID 16641)
-- Name: attend_scholastic_periods; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.attend_scholastic_periods (
    id bigint NOT NULL,
    scholastic_period_id bigint,
    attend_id bigint,
    enrollment_date date,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    classroom_id bigint,
    parent1_id integer,
    parent2_id integer
);


ALTER TABLE public.attend_scholastic_periods OWNER TO postgres;

--
-- TOC entry 252 (class 1259 OID 16640)
-- Name: attend_scholastic_periods_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.attend_scholastic_periods_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.attend_scholastic_periods_id_seq OWNER TO postgres;

--
-- TOC entry 4061 (class 0 OID 0)
-- Dependencies: 252
-- Name: attend_scholastic_periods_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.attend_scholastic_periods_id_seq OWNED BY public.attend_scholastic_periods.id;


--
-- TOC entry 249 (class 1259 OID 16622)
-- Name: attends; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.attends (
    id bigint NOT NULL,
    school_id bigint,
    student_id bigint,
    registration_number character varying,
    first_enrollment_date date,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.attends OWNER TO postgres;

--
-- TOC entry 248 (class 1259 OID 16621)
-- Name: attends_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.attends_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.attends_id_seq OWNER TO postgres;

--
-- TOC entry 4062 (class 0 OID 0)
-- Dependencies: 248
-- Name: attends_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.attends_id_seq OWNED BY public.attends.id;


--
-- TOC entry 263 (class 1259 OID 16717)
-- Name: classrooms; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.classrooms (
    id bigint NOT NULL,
    number_of_students integer DEFAULT 0,
    class_level_id bigint,
    local_id bigint,
    cycle_id bigint,
    specialty_id integer
);


ALTER TABLE public.classrooms OWNER TO postgres;

--
-- TOC entry 262 (class 1259 OID 16716)
-- Name: classrooms_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.classrooms_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.classrooms_id_seq OWNER TO postgres;

--
-- TOC entry 4063 (class 0 OID 0)
-- Dependencies: 262
-- Name: classrooms_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.classrooms_id_seq OWNED BY public.classrooms.id;


--
-- TOC entry 271 (class 1259 OID 16804)
-- Name: courses; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.courses (
    id bigint NOT NULL,
    classroom_id bigint,
    scholastic_period_id bigint DEFAULT 1 NOT NULL
);


ALTER TABLE public.courses OWNER TO postgres;

--
-- TOC entry 270 (class 1259 OID 16803)
-- Name: courses_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.courses_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.courses_id_seq OWNER TO postgres;

--
-- TOC entry 4064 (class 0 OID 0)
-- Dependencies: 270
-- Name: courses_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.courses_id_seq OWNED BY public.courses.id;


--
-- TOC entry 281 (class 1259 OID 16888)
-- Name: decode_configurations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.decode_configurations (
    id bigint NOT NULL,
    group_key character varying NOT NULL,
    common boolean DEFAULT false
);


ALTER TABLE public.decode_configurations OWNER TO postgres;

--
-- TOC entry 280 (class 1259 OID 16887)
-- Name: decode_configurations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.decode_configurations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.decode_configurations_id_seq OWNER TO postgres;

--
-- TOC entry 4065 (class 0 OID 0)
-- Dependencies: 280
-- Name: decode_configurations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.decode_configurations_id_seq OWNED BY public.decode_configurations.id;


--
-- TOC entry 285 (class 1259 OID 16922)
-- Name: decode_relations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.decode_relations (
    id bigint NOT NULL,
    decode_id bigint NOT NULL,
    decodable_type character varying NOT NULL,
    decodable_id bigint NOT NULL,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.decode_relations OWNER TO postgres;

--
-- TOC entry 284 (class 1259 OID 16921)
-- Name: decode_relations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.decode_relations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.decode_relations_id_seq OWNER TO postgres;

--
-- TOC entry 4066 (class 0 OID 0)
-- Dependencies: 284
-- Name: decode_relations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.decode_relations_id_seq OWNED BY public.decode_relations.id;


--
-- TOC entry 283 (class 1259 OID 16899)
-- Name: decodes; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.decodes (
    id bigint NOT NULL,
    decode_configuration_id bigint NOT NULL,
    school_id bigint NOT NULL,
    cod character varying NOT NULL
);


ALTER TABLE public.decodes OWNER TO postgres;

--
-- TOC entry 282 (class 1259 OID 16898)
-- Name: decodes_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.decodes_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.decodes_id_seq OWNER TO postgres;

--
-- TOC entry 4067 (class 0 OID 0)
-- Dependencies: 282
-- Name: decodes_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.decodes_id_seq OWNED BY public.decodes.id;


--
-- TOC entry 265 (class 1259 OID 16748)
-- Name: departments; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.departments (
    id bigint NOT NULL
);


ALTER TABLE public.departments OWNER TO postgres;

--
-- TOC entry 264 (class 1259 OID 16747)
-- Name: departments_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.departments_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.departments_id_seq OWNER TO postgres;

--
-- TOC entry 4068 (class 0 OID 0)
-- Dependencies: 264
-- Name: departments_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.departments_id_seq OWNED BY public.departments.id;


--
-- TOC entry 245 (class 1259 OID 16601)
-- Name: detail_translations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.detail_translations (
    id bigint NOT NULL,
    detail_id bigint NOT NULL,
    locale character varying NOT NULL,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    denomination character varying,
    description text
);


ALTER TABLE public.detail_translations OWNER TO postgres;

--
-- TOC entry 244 (class 1259 OID 16600)
-- Name: detail_translations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.detail_translations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.detail_translations_id_seq OWNER TO postgres;

--
-- TOC entry 4069 (class 0 OID 0)
-- Dependencies: 244
-- Name: detail_translations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.detail_translations_id_seq OWNED BY public.detail_translations.id;


--
-- TOC entry 243 (class 1259 OID 16591)
-- Name: details; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.details (
    id bigint NOT NULL,
    actable_type character varying,
    actable_id bigint,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.details OWNER TO postgres;

--
-- TOC entry 242 (class 1259 OID 16590)
-- Name: details_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.details_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.details_id_seq OWNER TO postgres;

--
-- TOC entry 4070 (class 0 OID 0)
-- Dependencies: 242
-- Name: details_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.details_id_seq OWNED BY public.details.id;


--
-- TOC entry 261 (class 1259 OID 16710)
-- Name: evaluation_types; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.evaluation_types (
    id bigint NOT NULL
);


ALTER TABLE public.evaluation_types OWNER TO postgres;

--
-- TOC entry 260 (class 1259 OID 16709)
-- Name: evaluation_types_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.evaluation_types_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.evaluation_types_id_seq OWNER TO postgres;

--
-- TOC entry 4071 (class 0 OID 0)
-- Dependencies: 260
-- Name: evaluation_types_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.evaluation_types_id_seq OWNED BY public.evaluation_types.id;


--
-- TOC entry 273 (class 1259 OID 16817)
-- Name: evaluations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.evaluations (
    id bigint NOT NULL,
    evaluation_date date,
    start_time time without time zone DEFAULT '00:00:00'::time without time zone,
    end_time time without time zone DEFAULT '00:00:00'::time without time zone,
    course_id bigint NOT NULL,
    evaluation_type_id bigint NOT NULL,
    local_id bigint
);


ALTER TABLE public.evaluations OWNER TO postgres;

--
-- TOC entry 272 (class 1259 OID 16816)
-- Name: evaluations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.evaluations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.evaluations_id_seq OWNER TO postgres;

--
-- TOC entry 4072 (class 0 OID 0)
-- Dependencies: 272
-- Name: evaluations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.evaluations_id_seq OWNED BY public.evaluations.id;


--
-- TOC entry 231 (class 1259 OID 16524)
-- Name: extra_activities; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.extra_activities (
    id bigint NOT NULL,
    category character varying,
    denomination character varying,
    our_meetings character varying,
    preferences jsonb DEFAULT '"{}"'::jsonb NOT NULL,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.extra_activities OWNER TO postgres;

--
-- TOC entry 230 (class 1259 OID 16523)
-- Name: extra_activities_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.extra_activities_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.extra_activities_id_seq OWNER TO postgres;

--
-- TOC entry 4073 (class 0 OID 0)
-- Dependencies: 230
-- Name: extra_activities_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.extra_activities_id_seq OWNED BY public.extra_activities.id;


--
-- TOC entry 241 (class 1259 OID 16576)
-- Name: institutions; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.institutions (
    id bigint NOT NULL,
    institutionalisable_id integer,
    institutionalisable_type character varying,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    school_id bigint NOT NULL
);


ALTER TABLE public.institutions OWNER TO postgres;

--
-- TOC entry 240 (class 1259 OID 16575)
-- Name: institutions_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.institutions_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.institutions_id_seq OWNER TO postgres;

--
-- TOC entry 4074 (class 0 OID 0)
-- Dependencies: 240
-- Name: institutions_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.institutions_id_seq OWNED BY public.institutions.id;


--
-- TOC entry 222 (class 1259 OID 16467)
-- Name: jwt_denylists; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.jwt_denylists (
    id bigint NOT NULL,
    jti character varying NOT NULL,
    expired_at timestamp without time zone NOT NULL
);


ALTER TABLE public.jwt_denylists OWNER TO postgres;

--
-- TOC entry 221 (class 1259 OID 16466)
-- Name: jwt_denylists_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.jwt_denylists_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.jwt_denylists_id_seq OWNER TO postgres;

--
-- TOC entry 4075 (class 0 OID 0)
-- Dependencies: 221
-- Name: jwt_denylists_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.jwt_denylists_id_seq OWNED BY public.jwt_denylists.id;


--
-- TOC entry 259 (class 1259 OID 16694)
-- Name: locals; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.locals (
    id bigint NOT NULL,
    capacity integer,
    localisation character varying
);


ALTER TABLE public.locals OWNER TO postgres;

--
-- TOC entry 258 (class 1259 OID 16693)
-- Name: locals_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.locals_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.locals_id_seq OWNER TO postgres;

--
-- TOC entry 4076 (class 0 OID 0)
-- Dependencies: 258
-- Name: locals_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.locals_id_seq OWNED BY public.locals.id;


--
-- TOC entry 239 (class 1259 OID 16564)
-- Name: monitorings; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.monitorings (
    id bigint NOT NULL,
    status integer DEFAULT 4,
    start_date timestamp without time zone,
    end_date timestamp without time zone,
    create_who_id bigint,
    update_who_id bigint,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    monitorable_type character varying NOT NULL,
    monitorable_id bigint NOT NULL
);


ALTER TABLE public.monitorings OWNER TO postgres;

--
-- TOC entry 238 (class 1259 OID 16563)
-- Name: monitorings_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.monitorings_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.monitorings_id_seq OWNER TO postgres;

--
-- TOC entry 4077 (class 0 OID 0)
-- Dependencies: 238
-- Name: monitorings_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.monitorings_id_seq OWNED BY public.monitorings.id;


--
-- TOC entry 279 (class 1259 OID 16877)
-- Name: parent_translations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.parent_translations (
    id bigint NOT NULL,
    parent_id bigint NOT NULL,
    locale character varying NOT NULL,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    occupation character varying
);


ALTER TABLE public.parent_translations OWNER TO postgres;

--
-- TOC entry 278 (class 1259 OID 16876)
-- Name: parent_translations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.parent_translations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.parent_translations_id_seq OWNER TO postgres;

--
-- TOC entry 4078 (class 0 OID 0)
-- Dependencies: 278
-- Name: parent_translations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.parent_translations_id_seq OWNED BY public.parent_translations.id;


--
-- TOC entry 277 (class 1259 OID 16870)
-- Name: parents; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.parents (
    id bigint NOT NULL,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.parents OWNER TO postgres;

--
-- TOC entry 276 (class 1259 OID 16869)
-- Name: parents_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.parents_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.parents_id_seq OWNER TO postgres;

--
-- TOC entry 4079 (class 0 OID 0)
-- Dependencies: 276
-- Name: parents_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.parents_id_seq OWNED BY public.parents.id;


--
-- TOC entry 224 (class 1259 OID 16477)
-- Name: roles; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.roles (
    id bigint NOT NULL,
    name character varying,
    resource_type character varying,
    resource_id bigint,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.roles OWNER TO postgres;

--
-- TOC entry 223 (class 1259 OID 16476)
-- Name: roles_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.roles_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.roles_id_seq OWNER TO postgres;

--
-- TOC entry 4080 (class 0 OID 0)
-- Dependencies: 223
-- Name: roles_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.roles_id_seq OWNED BY public.roles.id;


--
-- TOC entry 209 (class 1259 OID 16387)
-- Name: schema_migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.schema_migrations (
    version character varying NOT NULL
);


ALTER TABLE public.schema_migrations OWNER TO postgres;

--
-- TOC entry 251 (class 1259 OID 16634)
-- Name: scholastic_periods; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.scholastic_periods (
    id bigint NOT NULL
);


ALTER TABLE public.scholastic_periods OWNER TO postgres;

--
-- TOC entry 250 (class 1259 OID 16633)
-- Name: scholastic_periods_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.scholastic_periods_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.scholastic_periods_id_seq OWNER TO postgres;

--
-- TOC entry 4081 (class 0 OID 0)
-- Dependencies: 250
-- Name: scholastic_periods_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.scholastic_periods_id_seq OWNED BY public.scholastic_periods.id;


--
-- TOC entry 227 (class 1259 OID 16499)
-- Name: school_translations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.school_translations (
    id bigint NOT NULL,
    school_id bigint NOT NULL,
    locale character varying NOT NULL,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    sub_denomination text,
    admission_generality text,
    sub_description text,
    slogan text,
    history text,
    terms_condition text,
    privacy_policy text,
    protocol text,
    cookies_policy text,
    social text,
    activities_description text,
    internal_rules text,
    mission text,
    vision text,
    location_url character varying
);


ALTER TABLE public.school_translations OWNER TO postgres;

--
-- TOC entry 226 (class 1259 OID 16498)
-- Name: school_translations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.school_translations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.school_translations_id_seq OWNER TO postgres;

--
-- TOC entry 4082 (class 0 OID 0)
-- Dependencies: 226
-- Name: school_translations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.school_translations_id_seq OWNED BY public.school_translations.id;


--
-- TOC entry 218 (class 1259 OID 16443)
-- Name: schools; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.schools (
    id bigint NOT NULL,
    denomination character varying,
    contacts_info jsonb DEFAULT '"{}"'::jsonb NOT NULL,
    social_media jsonb DEFAULT '"{}"'::jsonb NOT NULL,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    identification_number character varying,
    theme_id bigint,
    root_id bigint,
    parent_id bigint,
    category_id integer DEFAULT 1 NOT NULL,
    permissions jsonb DEFAULT '{}'::jsonb
);


ALTER TABLE public.schools OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 16442)
-- Name: schools_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.schools_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.schools_id_seq OWNER TO postgres;

--
-- TOC entry 4083 (class 0 OID 0)
-- Dependencies: 217
-- Name: schools_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.schools_id_seq OWNED BY public.schools.id;


--
-- TOC entry 269 (class 1259 OID 16789)
-- Name: serves; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.serves (
    id bigint NOT NULL,
    school_id bigint,
    staff_id bigint,
    job_id bigint,
    profile_id bigint,
    departement_id bigint,
    first_serving_date date,
    is_school_admin boolean DEFAULT false,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.serves OWNER TO postgres;

--
-- TOC entry 268 (class 1259 OID 16788)
-- Name: serves_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.serves_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.serves_id_seq OWNER TO postgres;

--
-- TOC entry 4084 (class 0 OID 0)
-- Dependencies: 268
-- Name: serves_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.serves_id_seq OWNED BY public.serves.id;


--
-- TOC entry 267 (class 1259 OID 16779)
-- Name: staffs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.staffs (
    id bigint NOT NULL,
    infos json DEFAULT '{}'::json,
    signature text DEFAULT ''::text
);


ALTER TABLE public.staffs OWNER TO postgres;

--
-- TOC entry 266 (class 1259 OID 16778)
-- Name: staffs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.staffs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.staffs_id_seq OWNER TO postgres;

--
-- TOC entry 4085 (class 0 OID 0)
-- Dependencies: 266
-- Name: staffs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.staffs_id_seq OWNED BY public.staffs.id;


--
-- TOC entry 257 (class 1259 OID 16661)
-- Name: states; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.states (
    id bigint NOT NULL,
    "isEnable" boolean DEFAULT false,
    actable_type character varying,
    actable_id bigint
);


ALTER TABLE public.states OWNER TO postgres;

--
-- TOC entry 256 (class 1259 OID 16660)
-- Name: states_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.states_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.states_id_seq OWNER TO postgres;

--
-- TOC entry 4086 (class 0 OID 0)
-- Dependencies: 256
-- Name: states_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.states_id_seq OWNED BY public.states.id;


--
-- TOC entry 247 (class 1259 OID 16612)
-- Name: students; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.students (
    id bigint NOT NULL,
    primary_school character varying
);


ALTER TABLE public.students OWNER TO postgres;

--
-- TOC entry 246 (class 1259 OID 16611)
-- Name: students_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.students_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.students_id_seq OWNER TO postgres;

--
-- TOC entry 4087 (class 0 OID 0)
-- Dependencies: 246
-- Name: students_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.students_id_seq OWNED BY public.students.id;


--
-- TOC entry 237 (class 1259 OID 16553)
-- Name: table_description_translations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.table_description_translations (
    id bigint NOT NULL,
    table_description_id bigint NOT NULL,
    locale character varying NOT NULL,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    description text
);


ALTER TABLE public.table_description_translations OWNER TO postgres;

--
-- TOC entry 236 (class 1259 OID 16552)
-- Name: table_description_translations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.table_description_translations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.table_description_translations_id_seq OWNER TO postgres;

--
-- TOC entry 4088 (class 0 OID 0)
-- Dependencies: 236
-- Name: table_description_translations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.table_description_translations_id_seq OWNED BY public.table_description_translations.id;


--
-- TOC entry 235 (class 1259 OID 16544)
-- Name: table_descriptions; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.table_descriptions (
    id bigint NOT NULL,
    category character varying,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.table_descriptions OWNER TO postgres;

--
-- TOC entry 234 (class 1259 OID 16543)
-- Name: table_descriptions_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.table_descriptions_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.table_descriptions_id_seq OWNER TO postgres;

--
-- TOC entry 4089 (class 0 OID 0)
-- Dependencies: 234
-- Name: table_descriptions_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.table_descriptions_id_seq OWNED BY public.table_descriptions.id;


--
-- TOC entry 229 (class 1259 OID 16512)
-- Name: themes; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.themes (
    id bigint NOT NULL,
    denomination character varying,
    colors jsonb DEFAULT '"{}"'::jsonb NOT NULL,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL
);


ALTER TABLE public.themes OWNER TO postgres;

--
-- TOC entry 228 (class 1259 OID 16511)
-- Name: themes_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.themes_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.themes_id_seq OWNER TO postgres;

--
-- TOC entry 4090 (class 0 OID 0)
-- Dependencies: 228
-- Name: themes_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.themes_id_seq OWNED BY public.themes.id;


--
-- TOC entry 220 (class 1259 OID 16454)
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    email character varying DEFAULT ''::character varying NOT NULL,
    encrypted_password character varying DEFAULT ''::character varying NOT NULL,
    reset_password_token character varying,
    reset_password_sent_at timestamp without time zone,
    remember_created_at timestamp without time zone,
    created_at timestamp(6) without time zone NOT NULL,
    updated_at timestamp(6) without time zone NOT NULL,
    first_name character varying,
    last_name character varying,
    sex character varying,
    birthday jsonb DEFAULT '"{}"'::jsonb NOT NULL,
    phones jsonb DEFAULT '"{}"'::jsonb NOT NULL,
    address jsonb DEFAULT '"{}"'::jsonb NOT NULL,
    email_confirmed boolean DEFAULT false,
    confirmation_token character varying,
    confirmation_sent_at timestamp without time zone,
    confirmed_at timestamp without time zone,
    unconfirmed_email character varying,
    password_reset_expiry_date timestamp without time zone,
    identification_number character varying,
    userable_type character varying,
    userable_id bigint,
    is_admin boolean DEFAULT false,
    preferences jsonb DEFAULT '"{}"'::jsonb,
    avatar_url character varying
);


ALTER TABLE public.users OWNER TO postgres;

--
-- TOC entry 219 (class 1259 OID 16453)
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.users_id_seq OWNER TO postgres;

--
-- TOC entry 4091 (class 0 OID 0)
-- Dependencies: 219
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- TOC entry 225 (class 1259 OID 16486)
-- Name: users_roles; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users_roles (
    user_id bigint,
    role_id bigint
);


ALTER TABLE public.users_roles OWNER TO postgres;

--
-- TOC entry 3691 (class 2604 OID 16415)
-- Name: active_storage_attachments id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.active_storage_attachments ALTER COLUMN id SET DEFAULT nextval('public.active_storage_attachments_id_seq'::regclass);


--
-- TOC entry 3690 (class 2604 OID 16405)
-- Name: active_storage_blobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.active_storage_blobs ALTER COLUMN id SET DEFAULT nextval('public.active_storage_blobs_id_seq'::regclass);


--
-- TOC entry 3692 (class 2604 OID 16431)
-- Name: active_storage_variant_records id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.active_storage_variant_records ALTER COLUMN id SET DEFAULT nextval('public.active_storage_variant_records_id_seq'::regclass);


--
-- TOC entry 3726 (class 2604 OID 16653)
-- Name: activity_students id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.activity_students ALTER COLUMN id SET DEFAULT nextval('public.activity_students_id_seq'::regclass);


--
-- TOC entry 3714 (class 2604 OID 16537)
-- Name: attachments id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attachments ALTER COLUMN id SET DEFAULT nextval('public.attachments_id_seq'::regclass);


--
-- TOC entry 3744 (class 2604 OID 16847)
-- Name: attend_scholastic_period_evaluations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attend_scholastic_period_evaluations ALTER COLUMN id SET DEFAULT nextval('public.attend_scholastic_period_evaluations_id_seq'::regclass);


--
-- TOC entry 3725 (class 2604 OID 16644)
-- Name: attend_scholastic_periods id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attend_scholastic_periods ALTER COLUMN id SET DEFAULT nextval('public.attend_scholastic_periods_id_seq'::regclass);


--
-- TOC entry 3723 (class 2604 OID 16625)
-- Name: attends id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attends ALTER COLUMN id SET DEFAULT nextval('public.attends_id_seq'::regclass);


--
-- TOC entry 3731 (class 2604 OID 16720)
-- Name: classrooms id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.classrooms ALTER COLUMN id SET DEFAULT nextval('public.classrooms_id_seq'::regclass);


--
-- TOC entry 3739 (class 2604 OID 16807)
-- Name: courses id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.courses ALTER COLUMN id SET DEFAULT nextval('public.courses_id_seq'::regclass);


--
-- TOC entry 3747 (class 2604 OID 16891)
-- Name: decode_configurations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.decode_configurations ALTER COLUMN id SET DEFAULT nextval('public.decode_configurations_id_seq'::regclass);


--
-- TOC entry 3750 (class 2604 OID 16925)
-- Name: decode_relations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.decode_relations ALTER COLUMN id SET DEFAULT nextval('public.decode_relations_id_seq'::regclass);


--
-- TOC entry 3749 (class 2604 OID 16902)
-- Name: decodes id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.decodes ALTER COLUMN id SET DEFAULT nextval('public.decodes_id_seq'::regclass);


--
-- TOC entry 3733 (class 2604 OID 16751)
-- Name: departments id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.departments ALTER COLUMN id SET DEFAULT nextval('public.departments_id_seq'::regclass);


--
-- TOC entry 3721 (class 2604 OID 16604)
-- Name: detail_translations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.detail_translations ALTER COLUMN id SET DEFAULT nextval('public.detail_translations_id_seq'::regclass);


--
-- TOC entry 3720 (class 2604 OID 16594)
-- Name: details id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.details ALTER COLUMN id SET DEFAULT nextval('public.details_id_seq'::regclass);


--
-- TOC entry 3730 (class 2604 OID 16713)
-- Name: evaluation_types id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.evaluation_types ALTER COLUMN id SET DEFAULT nextval('public.evaluation_types_id_seq'::regclass);


--
-- TOC entry 3741 (class 2604 OID 16820)
-- Name: evaluations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.evaluations ALTER COLUMN id SET DEFAULT nextval('public.evaluations_id_seq'::regclass);


--
-- TOC entry 3712 (class 2604 OID 16527)
-- Name: extra_activities id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.extra_activities ALTER COLUMN id SET DEFAULT nextval('public.extra_activities_id_seq'::regclass);


--
-- TOC entry 3719 (class 2604 OID 16579)
-- Name: institutions id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.institutions ALTER COLUMN id SET DEFAULT nextval('public.institutions_id_seq'::regclass);


--
-- TOC entry 3707 (class 2604 OID 16470)
-- Name: jwt_denylists id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jwt_denylists ALTER COLUMN id SET DEFAULT nextval('public.jwt_denylists_id_seq'::regclass);


--
-- TOC entry 3729 (class 2604 OID 16697)
-- Name: locals id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.locals ALTER COLUMN id SET DEFAULT nextval('public.locals_id_seq'::regclass);


--
-- TOC entry 3717 (class 2604 OID 16567)
-- Name: monitorings id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.monitorings ALTER COLUMN id SET DEFAULT nextval('public.monitorings_id_seq'::regclass);


--
-- TOC entry 3746 (class 2604 OID 16880)
-- Name: parent_translations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.parent_translations ALTER COLUMN id SET DEFAULT nextval('public.parent_translations_id_seq'::regclass);


--
-- TOC entry 3745 (class 2604 OID 16873)
-- Name: parents id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.parents ALTER COLUMN id SET DEFAULT nextval('public.parents_id_seq'::regclass);


--
-- TOC entry 3708 (class 2604 OID 16480)
-- Name: roles id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.roles ALTER COLUMN id SET DEFAULT nextval('public.roles_id_seq'::regclass);


--
-- TOC entry 3724 (class 2604 OID 16637)
-- Name: scholastic_periods id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.scholastic_periods ALTER COLUMN id SET DEFAULT nextval('public.scholastic_periods_id_seq'::regclass);


--
-- TOC entry 3709 (class 2604 OID 16502)
-- Name: school_translations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.school_translations ALTER COLUMN id SET DEFAULT nextval('public.school_translations_id_seq'::regclass);


--
-- TOC entry 3693 (class 2604 OID 16446)
-- Name: schools id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schools ALTER COLUMN id SET DEFAULT nextval('public.schools_id_seq'::regclass);


--
-- TOC entry 3737 (class 2604 OID 16792)
-- Name: serves id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.serves ALTER COLUMN id SET DEFAULT nextval('public.serves_id_seq'::regclass);


--
-- TOC entry 3734 (class 2604 OID 16782)
-- Name: staffs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.staffs ALTER COLUMN id SET DEFAULT nextval('public.staffs_id_seq'::regclass);


--
-- TOC entry 3727 (class 2604 OID 16664)
-- Name: states id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.states ALTER COLUMN id SET DEFAULT nextval('public.states_id_seq'::regclass);


--
-- TOC entry 3722 (class 2604 OID 16615)
-- Name: students id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.students ALTER COLUMN id SET DEFAULT nextval('public.students_id_seq'::regclass);


--
-- TOC entry 3716 (class 2604 OID 16556)
-- Name: table_description_translations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.table_description_translations ALTER COLUMN id SET DEFAULT nextval('public.table_description_translations_id_seq'::regclass);


--
-- TOC entry 3715 (class 2604 OID 16547)
-- Name: table_descriptions id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.table_descriptions ALTER COLUMN id SET DEFAULT nextval('public.table_descriptions_id_seq'::regclass);


--
-- TOC entry 3710 (class 2604 OID 16515)
-- Name: themes id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.themes ALTER COLUMN id SET DEFAULT nextval('public.themes_id_seq'::regclass);


--
-- TOC entry 3698 (class 2604 OID 16457)
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- TOC entry 3759 (class 2606 OID 16419)
-- Name: active_storage_attachments active_storage_attachments_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.active_storage_attachments
    ADD CONSTRAINT active_storage_attachments_pkey PRIMARY KEY (id);


--
-- TOC entry 3756 (class 2606 OID 16409)
-- Name: active_storage_blobs active_storage_blobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.active_storage_blobs
    ADD CONSTRAINT active_storage_blobs_pkey PRIMARY KEY (id);


--
-- TOC entry 3763 (class 2606 OID 16435)
-- Name: active_storage_variant_records active_storage_variant_records_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.active_storage_variant_records
    ADD CONSTRAINT active_storage_variant_records_pkey PRIMARY KEY (id);


--
-- TOC entry 3835 (class 2606 OID 16657)
-- Name: activity_students activity_students_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.activity_students
    ADD CONSTRAINT activity_students_pkey PRIMARY KEY (id);


--
-- TOC entry 3754 (class 2606 OID 16400)
-- Name: ar_internal_metadata ar_internal_metadata_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ar_internal_metadata
    ADD CONSTRAINT ar_internal_metadata_pkey PRIMARY KEY (key);


--
-- TOC entry 3798 (class 2606 OID 16541)
-- Name: attachments attachments_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attachments
    ADD CONSTRAINT attachments_pkey PRIMARY KEY (id);


--
-- TOC entry 3871 (class 2606 OID 16849)
-- Name: attend_scholastic_period_evaluations attend_scholastic_period_evaluations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attend_scholastic_period_evaluations
    ADD CONSTRAINT attend_scholastic_period_evaluations_pkey PRIMARY KEY (id);


--
-- TOC entry 3831 (class 2606 OID 16646)
-- Name: attend_scholastic_periods attend_scholastic_periods_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attend_scholastic_periods
    ADD CONSTRAINT attend_scholastic_periods_pkey PRIMARY KEY (id);


--
-- TOC entry 3824 (class 2606 OID 16629)
-- Name: attends attends_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attends
    ADD CONSTRAINT attends_pkey PRIMARY KEY (id);


--
-- TOC entry 3846 (class 2606 OID 16723)
-- Name: classrooms classrooms_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.classrooms
    ADD CONSTRAINT classrooms_pkey PRIMARY KEY (id);


--
-- TOC entry 3862 (class 2606 OID 16809)
-- Name: courses courses_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.courses
    ADD CONSTRAINT courses_pkey PRIMARY KEY (id);


--
-- TOC entry 3881 (class 2606 OID 16896)
-- Name: decode_configurations decode_configurations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.decode_configurations
    ADD CONSTRAINT decode_configurations_pkey PRIMARY KEY (id);


--
-- TOC entry 3890 (class 2606 OID 16929)
-- Name: decode_relations decode_relations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.decode_relations
    ADD CONSTRAINT decode_relations_pkey PRIMARY KEY (id);


--
-- TOC entry 3884 (class 2606 OID 16906)
-- Name: decodes decodes_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.decodes
    ADD CONSTRAINT decodes_pkey PRIMARY KEY (id);


--
-- TOC entry 3851 (class 2606 OID 16753)
-- Name: departments departments_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.departments
    ADD CONSTRAINT departments_pkey PRIMARY KEY (id);


--
-- TOC entry 3818 (class 2606 OID 16608)
-- Name: detail_translations detail_translations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.detail_translations
    ADD CONSTRAINT detail_translations_pkey PRIMARY KEY (id);


--
-- TOC entry 3815 (class 2606 OID 16598)
-- Name: details details_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.details
    ADD CONSTRAINT details_pkey PRIMARY KEY (id);


--
-- TOC entry 3844 (class 2606 OID 16715)
-- Name: evaluation_types evaluation_types_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.evaluation_types
    ADD CONSTRAINT evaluation_types_pkey PRIMARY KEY (id);


--
-- TOC entry 3866 (class 2606 OID 16824)
-- Name: evaluations evaluations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.evaluations
    ADD CONSTRAINT evaluations_pkey PRIMARY KEY (id);


--
-- TOC entry 3796 (class 2606 OID 16532)
-- Name: extra_activities extra_activities_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.extra_activities
    ADD CONSTRAINT extra_activities_pkey PRIMARY KEY (id);


--
-- TOC entry 3813 (class 2606 OID 16583)
-- Name: institutions institutions_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.institutions
    ADD CONSTRAINT institutions_pkey PRIMARY KEY (id);


--
-- TOC entry 3780 (class 2606 OID 16474)
-- Name: jwt_denylists jwt_denylists_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jwt_denylists
    ADD CONSTRAINT jwt_denylists_pkey PRIMARY KEY (id);


--
-- TOC entry 3842 (class 2606 OID 16701)
-- Name: locals locals_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.locals
    ADD CONSTRAINT locals_pkey PRIMARY KEY (id);


--
-- TOC entry 3810 (class 2606 OID 16569)
-- Name: monitorings monitorings_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.monitorings
    ADD CONSTRAINT monitorings_pkey PRIMARY KEY (id);


--
-- TOC entry 3879 (class 2606 OID 16884)
-- Name: parent_translations parent_translations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.parent_translations
    ADD CONSTRAINT parent_translations_pkey PRIMARY KEY (id);


--
-- TOC entry 3875 (class 2606 OID 16875)
-- Name: parents parents_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.parents
    ADD CONSTRAINT parents_pkey PRIMARY KEY (id);


--
-- TOC entry 3784 (class 2606 OID 16484)
-- Name: roles roles_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.roles
    ADD CONSTRAINT roles_pkey PRIMARY KEY (id);


--
-- TOC entry 3752 (class 2606 OID 16393)
-- Name: schema_migrations schema_migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schema_migrations
    ADD CONSTRAINT schema_migrations_pkey PRIMARY KEY (version);


--
-- TOC entry 3829 (class 2606 OID 16639)
-- Name: scholastic_periods scholastic_periods_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.scholastic_periods
    ADD CONSTRAINT scholastic_periods_pkey PRIMARY KEY (id);


--
-- TOC entry 3791 (class 2606 OID 16506)
-- Name: school_translations school_translations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.school_translations
    ADD CONSTRAINT school_translations_pkey PRIMARY KEY (id);


--
-- TOC entry 3770 (class 2606 OID 16452)
-- Name: schools schools_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schools
    ADD CONSTRAINT schools_pkey PRIMARY KEY (id);


--
-- TOC entry 3860 (class 2606 OID 16795)
-- Name: serves serves_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.serves
    ADD CONSTRAINT serves_pkey PRIMARY KEY (id);


--
-- TOC entry 3853 (class 2606 OID 16787)
-- Name: staffs staffs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.staffs
    ADD CONSTRAINT staffs_pkey PRIMARY KEY (id);


--
-- TOC entry 3840 (class 2606 OID 16669)
-- Name: states states_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.states
    ADD CONSTRAINT states_pkey PRIMARY KEY (id);


--
-- TOC entry 3822 (class 2606 OID 16619)
-- Name: students students_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.students
    ADD CONSTRAINT students_pkey PRIMARY KEY (id);


--
-- TOC entry 3805 (class 2606 OID 16560)
-- Name: table_description_translations table_description_translations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.table_description_translations
    ADD CONSTRAINT table_description_translations_pkey PRIMARY KEY (id);


--
-- TOC entry 3801 (class 2606 OID 16551)
-- Name: table_descriptions table_descriptions_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.table_descriptions
    ADD CONSTRAINT table_descriptions_pkey PRIMARY KEY (id);


--
-- TOC entry 3794 (class 2606 OID 16520)
-- Name: themes themes_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.themes
    ADD CONSTRAINT themes_pkey PRIMARY KEY (id);


--
-- TOC entry 3777 (class 2606 OID 16463)
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- TOC entry 3760 (class 1259 OID 16425)
-- Name: index_active_storage_attachments_on_blob_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_active_storage_attachments_on_blob_id ON public.active_storage_attachments USING btree (blob_id);


--
-- TOC entry 3761 (class 1259 OID 16426)
-- Name: index_active_storage_attachments_uniqueness; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_active_storage_attachments_uniqueness ON public.active_storage_attachments USING btree (record_type, record_id, name, blob_id);


--
-- TOC entry 3757 (class 1259 OID 16410)
-- Name: index_active_storage_blobs_on_key; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_active_storage_blobs_on_key ON public.active_storage_blobs USING btree (key);


--
-- TOC entry 3764 (class 1259 OID 16441)
-- Name: index_active_storage_variant_records_uniqueness; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_active_storage_variant_records_uniqueness ON public.active_storage_variant_records USING btree (blob_id, variation_digest);


--
-- TOC entry 3836 (class 1259 OID 16659)
-- Name: index_activity_students_on_attend_scholastic_period_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_activity_students_on_attend_scholastic_period_id ON public.activity_students USING btree (attend_scholastic_period_id);


--
-- TOC entry 3837 (class 1259 OID 16658)
-- Name: index_activity_students_on_extra_activity_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_activity_students_on_extra_activity_id ON public.activity_students USING btree (extra_activity_id);


--
-- TOC entry 3799 (class 1259 OID 16542)
-- Name: index_attachments_on_attachable; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_attachments_on_attachable ON public.attachments USING btree (attachable_type, attachable_id);


--
-- TOC entry 3872 (class 1259 OID 16860)
-- Name: index_attend_evals_on_att_sch_period_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_attend_evals_on_att_sch_period_id ON public.attend_scholastic_period_evaluations USING btree (attend_scholastic_period_id);


--
-- TOC entry 3873 (class 1259 OID 16861)
-- Name: index_attend_scholastic_period_evaluations_on_evaluation_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_attend_scholastic_period_evaluations_on_evaluation_id ON public.attend_scholastic_period_evaluations USING btree (evaluation_id);


--
-- TOC entry 3832 (class 1259 OID 16648)
-- Name: index_attend_scholastic_periods_on_attend_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_attend_scholastic_periods_on_attend_id ON public.attend_scholastic_periods USING btree (attend_id);


--
-- TOC entry 3833 (class 1259 OID 16647)
-- Name: index_attend_scholastic_periods_on_scholastic_period_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_attend_scholastic_periods_on_scholastic_period_id ON public.attend_scholastic_periods USING btree (scholastic_period_id);


--
-- TOC entry 3825 (class 1259 OID 16632)
-- Name: index_attends_on_registration_number; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_attends_on_registration_number ON public.attends USING btree (registration_number);


--
-- TOC entry 3826 (class 1259 OID 16630)
-- Name: index_attends_on_school_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_attends_on_school_id ON public.attends USING btree (school_id);


--
-- TOC entry 3827 (class 1259 OID 16631)
-- Name: index_attends_on_student_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_attends_on_student_id ON public.attends USING btree (student_id);


--
-- TOC entry 3847 (class 1259 OID 16739)
-- Name: index_classrooms_on_class_level_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_classrooms_on_class_level_id ON public.classrooms USING btree (class_level_id);


--
-- TOC entry 3848 (class 1259 OID 16741)
-- Name: index_classrooms_on_cycle_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_classrooms_on_cycle_id ON public.classrooms USING btree (cycle_id);


--
-- TOC entry 3849 (class 1259 OID 16740)
-- Name: index_classrooms_on_local_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_classrooms_on_local_id ON public.classrooms USING btree (local_id);


--
-- TOC entry 3863 (class 1259 OID 16815)
-- Name: index_courses_on_classroom_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_courses_on_classroom_id ON public.courses USING btree (classroom_id);


--
-- TOC entry 3864 (class 1259 OID 16863)
-- Name: index_courses_on_scholastic_period_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_courses_on_scholastic_period_id ON public.courses USING btree (scholastic_period_id);


--
-- TOC entry 3882 (class 1259 OID 16897)
-- Name: index_decode_configurations_on_group_key; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_decode_configurations_on_group_key ON public.decode_configurations USING btree (group_key);


--
-- TOC entry 3891 (class 1259 OID 16936)
-- Name: index_decode_relations_on_decodable; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_decode_relations_on_decodable ON public.decode_relations USING btree (decodable_type, decodable_id);


--
-- TOC entry 3892 (class 1259 OID 16935)
-- Name: index_decode_relations_on_decode_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_decode_relations_on_decode_id ON public.decode_relations USING btree (decode_id);


--
-- TOC entry 3885 (class 1259 OID 16919)
-- Name: index_decodes_on_cod; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_decodes_on_cod ON public.decodes USING btree (cod);


--
-- TOC entry 3886 (class 1259 OID 16917)
-- Name: index_decodes_on_decode_configuration_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_decodes_on_decode_configuration_id ON public.decodes USING btree (decode_configuration_id);


--
-- TOC entry 3887 (class 1259 OID 16920)
-- Name: index_decodes_on_decode_configuration_id_and_school_id_and_cod; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_decodes_on_decode_configuration_id_and_school_id_and_cod ON public.decodes USING btree (decode_configuration_id, school_id, cod);


--
-- TOC entry 3888 (class 1259 OID 16918)
-- Name: index_decodes_on_school_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_decodes_on_school_id ON public.decodes USING btree (school_id);


--
-- TOC entry 3819 (class 1259 OID 16609)
-- Name: index_detail_translations_on_detail_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_detail_translations_on_detail_id ON public.detail_translations USING btree (detail_id);


--
-- TOC entry 3820 (class 1259 OID 16610)
-- Name: index_detail_translations_on_locale; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_detail_translations_on_locale ON public.detail_translations USING btree (locale);


--
-- TOC entry 3816 (class 1259 OID 16599)
-- Name: index_details_on_actable; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_details_on_actable ON public.details USING btree (actable_type, actable_id);


--
-- TOC entry 3867 (class 1259 OID 16840)
-- Name: index_evaluations_on_course_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_evaluations_on_course_id ON public.evaluations USING btree (course_id);


--
-- TOC entry 3868 (class 1259 OID 16841)
-- Name: index_evaluations_on_evaluation_type_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_evaluations_on_evaluation_type_id ON public.evaluations USING btree (evaluation_type_id);


--
-- TOC entry 3869 (class 1259 OID 16842)
-- Name: index_evaluations_on_local_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_evaluations_on_local_id ON public.evaluations USING btree (local_id);


--
-- TOC entry 3811 (class 1259 OID 16584)
-- Name: index_institutions_on_school_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_institutions_on_school_id ON public.institutions USING btree (school_id);


--
-- TOC entry 3778 (class 1259 OID 16475)
-- Name: index_jwt_denylists_on_jti; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_jwt_denylists_on_jti ON public.jwt_denylists USING btree (jti);


--
-- TOC entry 3806 (class 1259 OID 16570)
-- Name: index_monitorings_on_create_who_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_monitorings_on_create_who_id ON public.monitorings USING btree (create_who_id);


--
-- TOC entry 3807 (class 1259 OID 16574)
-- Name: index_monitorings_on_monitorable; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_monitorings_on_monitorable ON public.monitorings USING btree (monitorable_type, monitorable_id);


--
-- TOC entry 3808 (class 1259 OID 16571)
-- Name: index_monitorings_on_update_who_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_monitorings_on_update_who_id ON public.monitorings USING btree (update_who_id);


--
-- TOC entry 3876 (class 1259 OID 16886)
-- Name: index_parent_translations_on_locale; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_parent_translations_on_locale ON public.parent_translations USING btree (locale);


--
-- TOC entry 3877 (class 1259 OID 16885)
-- Name: index_parent_translations_on_parent_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_parent_translations_on_parent_id ON public.parent_translations USING btree (parent_id);


--
-- TOC entry 3781 (class 1259 OID 16491)
-- Name: index_roles_on_name_and_resource_type_and_resource_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_roles_on_name_and_resource_type_and_resource_id ON public.roles USING btree (name, resource_type, resource_id);


--
-- TOC entry 3782 (class 1259 OID 16485)
-- Name: index_roles_on_resource; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_roles_on_resource ON public.roles USING btree (resource_type, resource_id);


--
-- TOC entry 3788 (class 1259 OID 16508)
-- Name: index_school_translations_on_locale; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_school_translations_on_locale ON public.school_translations USING btree (locale);


--
-- TOC entry 3789 (class 1259 OID 16507)
-- Name: index_school_translations_on_school_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_school_translations_on_school_id ON public.school_translations USING btree (school_id);


--
-- TOC entry 3765 (class 1259 OID 16510)
-- Name: index_schools_on_identification_number; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_schools_on_identification_number ON public.schools USING btree (identification_number);


--
-- TOC entry 3766 (class 1259 OID 16679)
-- Name: index_schools_on_parent_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_schools_on_parent_id ON public.schools USING btree (parent_id);


--
-- TOC entry 3767 (class 1259 OID 16673)
-- Name: index_schools_on_root_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_schools_on_root_id ON public.schools USING btree (root_id);


--
-- TOC entry 3768 (class 1259 OID 16522)
-- Name: index_schools_on_theme_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_schools_on_theme_id ON public.schools USING btree (theme_id);


--
-- TOC entry 3854 (class 1259 OID 16800)
-- Name: index_serves_on_departement_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_serves_on_departement_id ON public.serves USING btree (departement_id);


--
-- TOC entry 3855 (class 1259 OID 16798)
-- Name: index_serves_on_job_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_serves_on_job_id ON public.serves USING btree (job_id);


--
-- TOC entry 3856 (class 1259 OID 16799)
-- Name: index_serves_on_profile_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_serves_on_profile_id ON public.serves USING btree (profile_id);


--
-- TOC entry 3857 (class 1259 OID 16796)
-- Name: index_serves_on_school_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_serves_on_school_id ON public.serves USING btree (school_id);


--
-- TOC entry 3858 (class 1259 OID 16797)
-- Name: index_serves_on_staff_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_serves_on_staff_id ON public.serves USING btree (staff_id);


--
-- TOC entry 3838 (class 1259 OID 16670)
-- Name: index_states_on_actable; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_states_on_actable ON public.states USING btree (actable_type, actable_id);


--
-- TOC entry 3802 (class 1259 OID 16562)
-- Name: index_table_description_translations_on_locale; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_table_description_translations_on_locale ON public.table_description_translations USING btree (locale);


--
-- TOC entry 3803 (class 1259 OID 16561)
-- Name: index_table_description_translations_on_table_description_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_table_description_translations_on_table_description_id ON public.table_description_translations USING btree (table_description_id);


--
-- TOC entry 3792 (class 1259 OID 16521)
-- Name: index_themes_on_denomination; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_themes_on_denomination ON public.themes USING btree (denomination);


--
-- TOC entry 3771 (class 1259 OID 16497)
-- Name: index_users_on_confirmation_token; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_users_on_confirmation_token ON public.users USING btree (confirmation_token);


--
-- TOC entry 3772 (class 1259 OID 16464)
-- Name: index_users_on_email; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_users_on_email ON public.users USING btree (email);


--
-- TOC entry 3773 (class 1259 OID 16509)
-- Name: index_users_on_identification_number; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_users_on_identification_number ON public.users USING btree (identification_number);


--
-- TOC entry 3774 (class 1259 OID 16465)
-- Name: index_users_on_reset_password_token; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_users_on_reset_password_token ON public.users USING btree (reset_password_token);


--
-- TOC entry 3775 (class 1259 OID 16620)
-- Name: index_users_on_userable; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_users_on_userable ON public.users USING btree (userable_type, userable_id);


--
-- TOC entry 3785 (class 1259 OID 16490)
-- Name: index_users_roles_on_role_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_users_roles_on_role_id ON public.users_roles USING btree (role_id);


--
-- TOC entry 3786 (class 1259 OID 16489)
-- Name: index_users_roles_on_user_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_users_roles_on_user_id ON public.users_roles USING btree (user_id);


--
-- TOC entry 3787 (class 1259 OID 16492)
-- Name: index_users_roles_on_user_id_and_role_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_users_roles_on_user_id_and_role_id ON public.users_roles USING btree (user_id, role_id);


--
-- TOC entry 3899 (class 2606 OID 16729)
-- Name: classrooms fk_rails_0278446abe; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.classrooms
    ADD CONSTRAINT fk_rails_0278446abe FOREIGN KEY (local_id) REFERENCES public.locals(id);


--
-- TOC entry 3907 (class 2606 OID 16912)
-- Name: decodes fk_rails_09761f25c1; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.decodes
    ADD CONSTRAINT fk_rails_09761f25c1 FOREIGN KEY (school_id) REFERENCES public.schools(id);


--
-- TOC entry 3909 (class 2606 OID 16930)
-- Name: decode_relations fk_rails_1930bccb69; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.decode_relations
    ADD CONSTRAINT fk_rails_1930bccb69 FOREIGN KEY (decode_id) REFERENCES public.decodes(id);


--
-- TOC entry 3905 (class 2606 OID 16855)
-- Name: attend_scholastic_period_evaluations fk_rails_2f43bd99ff; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attend_scholastic_period_evaluations
    ADD CONSTRAINT fk_rails_2f43bd99ff FOREIGN KEY (evaluation_id) REFERENCES public.evaluations(id);


--
-- TOC entry 3902 (class 2606 OID 16835)
-- Name: evaluations fk_rails_3cce3a10b5; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.evaluations
    ADD CONSTRAINT fk_rails_3cce3a10b5 FOREIGN KEY (local_id) REFERENCES public.locals(id);


--
-- TOC entry 3900 (class 2606 OID 16864)
-- Name: courses fk_rails_40c34991bd; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.courses
    ADD CONSTRAINT fk_rails_40c34991bd FOREIGN KEY (scholastic_period_id) REFERENCES public.scholastic_periods(id);


--
-- TOC entry 3908 (class 2606 OID 16907)
-- Name: decodes fk_rails_53aa9b22c1; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.decodes
    ADD CONSTRAINT fk_rails_53aa9b22c1 FOREIGN KEY (decode_configuration_id) REFERENCES public.decode_configurations(id);


--
-- TOC entry 3895 (class 2606 OID 16680)
-- Name: schools fk_rails_772fbc995b; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schools
    ADD CONSTRAINT fk_rails_772fbc995b FOREIGN KEY (parent_id) REFERENCES public.schools(id);


--
-- TOC entry 3894 (class 2606 OID 16436)
-- Name: active_storage_variant_records fk_rails_993965df05; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.active_storage_variant_records
    ADD CONSTRAINT fk_rails_993965df05 FOREIGN KEY (blob_id) REFERENCES public.active_storage_blobs(id);


--
-- TOC entry 3901 (class 2606 OID 16810)
-- Name: courses fk_rails_a1fca29269; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.courses
    ADD CONSTRAINT fk_rails_a1fca29269 FOREIGN KEY (classroom_id) REFERENCES public.classrooms(id);


--
-- TOC entry 3906 (class 2606 OID 16850)
-- Name: attend_scholastic_period_evaluations fk_rails_ab73b667de; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attend_scholastic_period_evaluations
    ADD CONSTRAINT fk_rails_ab73b667de FOREIGN KEY (attend_scholastic_period_id) REFERENCES public.attend_scholastic_periods(id);


--
-- TOC entry 3903 (class 2606 OID 16825)
-- Name: evaluations fk_rails_b85f1dd897; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.evaluations
    ADD CONSTRAINT fk_rails_b85f1dd897 FOREIGN KEY (course_id) REFERENCES public.courses(id);


--
-- TOC entry 3898 (class 2606 OID 16742)
-- Name: attend_scholastic_periods fk_rails_c2494509c8; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.attend_scholastic_periods
    ADD CONSTRAINT fk_rails_c2494509c8 FOREIGN KEY (classroom_id) REFERENCES public.classrooms(id);


--
-- TOC entry 3893 (class 2606 OID 16420)
-- Name: active_storage_attachments fk_rails_c3b3935057; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.active_storage_attachments
    ADD CONSTRAINT fk_rails_c3b3935057 FOREIGN KEY (blob_id) REFERENCES public.active_storage_blobs(id);


--
-- TOC entry 3896 (class 2606 OID 16674)
-- Name: schools fk_rails_dc59ab1fe8; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schools
    ADD CONSTRAINT fk_rails_dc59ab1fe8 FOREIGN KEY (root_id) REFERENCES public.schools(id);


--
-- TOC entry 3897 (class 2606 OID 16585)
-- Name: institutions fk_rails_ef15af322c; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.institutions
    ADD CONSTRAINT fk_rails_ef15af322c FOREIGN KEY (school_id) REFERENCES public.schools(id);


--
-- TOC entry 3904 (class 2606 OID 16830)
-- Name: evaluations fk_rails_f8dbacf4ab; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.evaluations
    ADD CONSTRAINT fk_rails_f8dbacf4ab FOREIGN KEY (evaluation_type_id) REFERENCES public.evaluation_types(id);


--
-- TOC entry 4054 (class 0 OID 0)
-- Dependencies: 4
-- Name: SCHEMA public; Type: ACL; Schema: -; Owner: solomontaiwo
--

REVOKE USAGE ON SCHEMA public FROM PUBLIC;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2024-06-03 16:33:58 CEST

--
-- PostgreSQL database dump complete
--

